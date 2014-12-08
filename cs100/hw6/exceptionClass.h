#include <stdexcept>
using namespace std;

class IndexOutOfBoundsException : public std::runtime_error
{
	public:
	IndexOutOfBoundsException(const string &message)
	: std::runtime_error(message)
	{};
};
