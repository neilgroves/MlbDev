//	////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////
//	MLB Utility Library Module File
//	////////////////////////////////////////////////////////////////////////////
/*
	File Name  			:	%M%

	File Version      :	%I%

	Last Extracted		:	%D%	%T%

	Last Updated		:	%E%	%U%

	File Description	:	Logic to support replacement of characters in strings.

	Revision History	:	2008-11-14 --- Creation.
									Michael L. Brock

		Copyright Michael L. Brock 2008 - 2014.
		Distributed under the Boost Software License, Version 1.0.
		(See accompanying file LICENSE_1_0.txt or copy at
		http://www.boost.org/LICENSE_1_0.txt)

*/
//	////////////////////////////////////////////////////////////////////////////
 
//	////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////
//	Required include files...
//	////////////////////////////////////////////////////////////////////////////

#include <Utility/ReplaceChars.hpp>

//	////////////////////////////////////////////////////////////////////////////

namespace MLB {

namespace Utility {

//	//////////////////////////////////////////////////////////////////////////
std::string &ReplaceCharsIn(const std::string &in_string,
	std::string &out_string, std::size_t from_char_count,
	const char *from_char_list, int to_char)
{
	out_string = in_string;

	std::string::size_type start_pos = 0;
	std::string::size_type found_pos;

	while ((found_pos = out_string.find_first_of(
		from_char_list, start_pos, from_char_count)) != std::string::npos) {
		out_string[found_pos] = static_cast<char>(to_char);
		start_pos             = found_pos + 1;
	}

	return(out_string);
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string &ReplaceCharsIn(const std::string &in_string,
	std::string &out_string, const std::string &from_char_list,
	int to_char)
{
	return(ReplaceCharsIn(in_string, out_string, from_char_list.size(),
		from_char_list.c_str(), to_char));
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string &ReplaceCharsIn(const std::string &in_string,
	std::string &out_string, int from_char, int to_char)
{
	char tmp_char = static_cast<char>(from_char);

	return(ReplaceCharsIn(in_string, out_string, 1, &tmp_char, to_char));
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string ReplaceCharsIn(const std::string &in_string,
	const std::string &from_char_list, int to_char)
{
	std::string out_string;

	return(ReplaceCharsIn(in_string, out_string, from_char_list, to_char));
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string ReplaceCharsIn(const std::string &in_string, int from_char,
	int to_char)
{
	std::string out_string;

	return(ReplaceCharsIn(in_string, out_string, from_char, to_char));
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string &ReplaceCharsNotIn(const std::string &in_string,
	std::string &out_string, std::size_t from_char_count,
	const char *from_char_list, int to_char)
{
	out_string = in_string;

	std::string::size_type start_pos = 0;
	std::string::size_type found_pos;

	while ((found_pos = out_string.find_first_not_of(
		from_char_list, start_pos, from_char_count)) != std::string::npos) {
		out_string[found_pos] = static_cast<char>(to_char);
		start_pos             = found_pos + 1;
	}

	return(out_string);
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string &ReplaceCharsNotIn(const std::string &in_string,
	std::string &out_string, const std::string &from_char_list,
	int to_char)
{
	return(ReplaceCharsNotIn(in_string, out_string, from_char_list.size(),
		from_char_list.c_str(), to_char));
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string &ReplaceCharsNotIn(const std::string &in_string,
	std::string &out_string, int from_char, int to_char)
{
	char tmp_char = static_cast<char>(from_char);

	return(ReplaceCharsNotIn(in_string, out_string, 1, &tmp_char, to_char));
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string ReplaceCharsNotIn(const std::string &in_string,
	const std::string &from_char_list, int to_char)
{
	std::string out_string;

	return(ReplaceCharsNotIn(in_string, out_string, from_char_list, to_char));
}
//	//////////////////////////////////////////////////////////////////////////

//	//////////////////////////////////////////////////////////////////////////
std::string ReplaceCharsNotIn(const std::string &in_string, int from_char,
	int to_char)
{
	std::string out_string;

	return(ReplaceCharsNotIn(in_string, out_string, from_char, to_char));
}
//	//////////////////////////////////////////////////////////////////////////

} // namespace Utility

} // namespace MLB

