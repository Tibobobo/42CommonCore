# include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {

}

Span::Span(Span const &src) {

	_maxSize = src.size();
	_v = src.getVect();
}

Span::~Span(void) {

}

Span &Span::operator=(Span const &rhs) {

	_maxSize = rhs.size();
	_v = rhs.getVect();
	return (*this);
}

unsigned int Span::size(void) const {

	return (this->_maxSize);
}

std::vector<int> Span::getVect(void) const {

	return (this->_v);
}

void	Span::addNumber(int n) {

	if (_v.size() >= _maxSize)
		throw (NoMoreSpaceException());
	else
		_v.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator const &start, std::vector<int>::iterator const &end) {

	unsigned int dist = std::distance(start, end);
	if (_v.size() + dist > _maxSize)
		throw (NoMoreSpaceException());
	else
		_v.insert(_v.end(), start, end);
}

unsigned int	Span::shortestSpan(void) const {

	if (_v.size() < 2)
		throw (NotEnoughNumbersException());
	std::vector<int> copy = _v;
	std::sort(copy.begin(), copy.end());

	std::vector<int>::iterator current,next;
	current = copy.begin();
	next = current + 1;
	unsigned int shortest = (std::abs(*next - *current));
	unsigned int diff = 0;
	while (next != copy.end())
	{
		diff = std::abs(*next - *current);
		if (shortest > diff)
			shortest = diff;
		current++;
		next++;
	}
	return (shortest);
}

unsigned int	Span::longestSpan(void) const {

	if (_v.size() < 2)
		throw (NotEnoughNumbersException());
	std::vector<int> copy = _v;
	std::sort(copy.begin(), copy.end());

	unsigned int longest = copy.back() - copy.front();
	return (longest);
}