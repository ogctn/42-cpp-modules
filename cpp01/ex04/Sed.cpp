#include "Sed.hpp"

Sed::Sed(std::string & infile, std::string & from, std::string & to) : 
	_infile_name(infile), _from(from), _to(to)
{
	this->_outfile_name = infile + ".replace";
}

Sed::~Sed()
{

}

std::string	&Sed::get_infile_name() const
{
	return (this->_infile_name);
}

std::string	Sed::get_outfile_name() const
{
	return (this->_outfile_name);
}

static std::string get_raw(std::string infile_name)
{
	std::ifstream inFile;

	inFile.open(infile_name, std::ios::in);
	if (!inFile.is_open())
	{
		std::cout << "Error: open: failed to open input file!" << std::endl;
		return ("");
	}

	std::string	raw;
	char		c_buff;

	while (inFile.get(c_buff))
		raw += c_buff;

	inFile.close();
	return (raw);
}

static int put_out_file(std::string outfile_name, std::string &content)
{
	std::ofstream outFile;

	outFile.open(outfile_name, std::ios::out);
	if (!outFile.is_open())
	{
		std::cout << "Error: open: failed to open" << outfile_name << "outFile file!" << std::endl;
		return (1);
	}

	outFile << content;
 	std::cout << "Mission Completed!" << std::endl;
	outFile.close();
	return (0);
}


int		Sed::operate() const
{

	std::string	raw = get_raw(this->_infile_name);
	if (raw.empty()) return (1);

	size_t pos = 0;

	while ((pos = raw.find(_from, pos)) != std::string::npos)
	{
		raw.erase(pos, _from.length());
		raw.insert(pos, _to);
		pos += _to.length();
	}

	return (put_out_file(this->_outfile_name, raw));
}
