template <typename T>
T	_stoval(const std::string &from) {
	std::stringstream ss(from);
	
	T converted;
	ss >> converted;
	return (converted);
}

template <typename T>
std::string _to_str(const T n) {
	std::stringstream ss;

	ss << n;
	return (ss.str());
}
