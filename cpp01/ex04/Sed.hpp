#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
	private:
		std::string &_infile_name;
		std::string _outfile_name;
		std::string &_from;
		std::string &_to;
	
	public:
		Sed(std::string & infile, std::string & from, std::string & to);
		~Sed();

		std::string	&get_infile_name() const;
		std::string	get_outfile_name() const;
		int			operate() const;		

};


#endif
