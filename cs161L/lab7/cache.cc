#include <iostream>
#include <vector>
#include <list>
#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cmath>

#define  BLOCK_SIZE     16
//#define  CACHE_SIZE     16384


unsigned long long mask_lookup[10] = {0x00000001, 0x00000003, 0x00000007, 0x0000000F, 0x0000001F,
									  0x0000003F, 0x0000007F, 0x000000FF, 0x000001FF, 0x000003FF};
									  
									  
void print_rates(const std::vector<double> &lru_rates, const std::vector<double> &fifo_rates)
{
	printf("	%s\n", "LRU Replacement Policy");
	printf("%-8s%-8d%-8d%-8d%-8d%-8d\n", "", 1024, 2048, 4096, 8192, 16384);
	for(int i = 0; i < 4; ++i)
	{
		printf("%-8d", (int)pow(2, i));
		printf("%-8.2lf", lru_rates[i] * 100.0);
		printf("%-8.2lf", lru_rates[i+4] * 100.0);
		printf("%-8.2lf", lru_rates[i+8] * 100.0);
		printf("%-8.2lf", lru_rates[i+12] * 100.0);
		printf("%-8.2lf", lru_rates[i+16] * 100.0);
		
		printf("\n");
	}
	printf("\n\n");
	printf("	%s\n", "FIFO Replacement Policy");
	printf("%-8s%-8d%-8d%-8d%-8d%-8d\n", "", 1024, 2048, 4096, 8192, 16384);
	for(int i = 0; i < 4; ++i)
	{
		printf("%-8d", (int)pow(2, i));
		printf("%-8.2lf", fifo_rates[i] * 100.0);
		printf("%-8.2lf", fifo_rates[i+4] * 100.0);
		printf("%-8.2lf", fifo_rates[i+8] * 100.0);
		printf("%-8.2lf", fifo_rates[i+12] * 100.0);
		printf("%-8.2lf", fifo_rates[i+16] * 100.0);
		
		printf("\n");
	}
	
	
}
									  
void init_lists(std::vector< std::vector< unsigned long long> > &cache, 
				std::vector< std::list< unsigned long long> > &lru_queue,
				int number_of_blocks, int assoc)
{
	for (int i = 0; i < number_of_blocks; ++i)
    {
		cache.push_back(std::vector< unsigned long long>());
		lru_queue.push_back(std::list<unsigned long long>());
		for(int e = 0; e < assoc; ++e)
		{
			cache[i].push_back(0);
			lru_queue[i].push_back(0);
		}
	}
}
	

void replacement(int cache_size, int assoc, std::vector<double> &rates, const std::string &rep_policy)
{
    int number_of_blocks = (cache_size / BLOCK_SIZE) / assoc;
    //number_of_blocks = number_of_blocks / assoc;
    int index_size = (int)(log(number_of_blocks) / log(2));
    int offset_size = 4, total = 0, miss = 0;
    unsigned long long read_line;
    
    //Initialize cache and LRU queue
    std::vector< std::vector< unsigned long long> > cache;
    std::vector< std::list<unsigned long long> > lru_queue;
    init_lists(cache, lru_queue, number_of_blocks, assoc);
    
    while (std::cin >> std::hex >> read_line) 
    {
        total++;
        unsigned long long tag   = read_line >> (index_size + offset_size); // get tag
        unsigned long long index = read_line >> offset_size;        // get index
        index = index & mask_lookup[index_size-1];

		//assure lru_queue and cache are synchronized
		assert(lru_queue[index].size() <= assoc && cache[index].size() <= assoc);
		
		//Check if tag is already in cache. If so, don't mark as miss.
		int i = 0;
		for(std::list<unsigned long long>::iterator it = lru_queue[index].begin(); it != lru_queue[index].end(); ++it)
		{
			if(*it == tag)
			{
				if(rep_policy != "lru") goto hit;
				
				cache[index].erase(cache[index].begin() + i);
				cache[index].insert(cache[index].begin(), tag);
				
				lru_queue[index].erase(it);
				lru_queue[index].push_front(tag);
				
				goto hit;
			}
			++i;
		}
		
		cache[index].pop_back();
		cache[index].insert(cache[index].begin(), tag);
		
		lru_queue[index].pop_back();
		lru_queue[index].push_front(tag);
		miss++;
		
		hit:;
		
    }
    
    std::cin.clear();
    std::cin.seekg(0, std::ios::beg);
    
    double miss_rate = (double)miss / (double)(total);
    rates.push_back(miss_rate);
    //printf("%0.2lf\n", miss_rate * 100.0);
}

int main () 
{
	int cache_sizes[5] = {1024, 2048, 4096, 8192, 16384};
   
	std::vector<double> lru_rates;
	std::vector<double> fifo_rates;
   
    for(int i = 0; i < 5; ++i)
    {
		for(int e = 0; e < 4; ++e)
		{
			replacement(cache_sizes[i], (int)pow(2,e), lru_rates, "lru");
			replacement(cache_sizes[i], (int)pow(2,e), fifo_rates, "fifo");
		}
    }
    print_rates(lru_rates, fifo_rates);

   return 0;
}
