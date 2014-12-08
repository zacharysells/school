#ifndef MYMAP_H
#define MYMAP_H
#define nil 0
#include <set>

template< typename Key, typename T>
class ppair
{
	public:
	const Key first;
	mutable T second;
	
	ppair(Key s, T t) 
	:first(s), second(t)
	{}
};

template<typename Key, typename T>
struct classcomp
{
	typedef ppair<const Key, T> Pair;
	bool operator() (const Pair& lhs, const Pair& rhs) const
	{
		return lhs.first < rhs.first;
	}
};

template <typename Key, typename T>
class map : public std::set<ppair<const Key, T>, classcomp<const Key, T> >
{
	public:
	typedef ppair< const Key, T> Pair;
	typedef std::set<Pair, classcomp<const Key, T> > Stuff;
	//std::set<Pair, classcomp<const Key, T> > myset;
	typename Stuff::iterator find(const Key& x) const
	{
		return Stuff::find(Pair(x, T()));
	}
	
	map()
	{
		//No default needed
	}
	
	map(const map& rhs)
	{
		Stuff::operator=(rhs);
	}
	
	map& operator=(const map& rhs)
	{
		Stuff::operator=(rhs);
	}
	
	~map()
	{
		//No destructor needed. No dynamic variables created.
	}
	
	typename Stuff::iterator end()
	{
		return Stuff::end();
	}
	
	T& operator[] (const Key x)
	{
		typename Stuff::iterator i = find(x);
		if(i == Stuff::end() )
		{
			insert(Pair(x, T()));
			i = find(x);
		}
		return (i->second);
	}
	
};

#endif
