//	////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////
//	SocketIo Portable Socket Library Include File.
//	////////////////////////////////////////////////////////////////////////////
/*
	File Name  			:	%M%

	File Version      :	%I%

	Last Extracted		:	%D%	%T%

	Last Updated		:	%E%	%U%

	File Description	:	Include file for class IpAddressGeneric.

	Revision History	:	2008-12-20 --- Creation
									Michael L. Brock

		Copyright Michael L. Brock 2008 - 2014.
		Distributed under the Boost Software License, Version 1.0.
		(See accompanying file LICENSE_1_0.txt or copy at
		http://www.boost.org/LICENSE_1_0.txt)

*/
//	////////////////////////////////////////////////////////////////////////////

#ifndef HH__MLB__SocketIo__IpAddressGeneric_hpp__HH

#define HH__MLB__SocketIo__IpAddressGeneric_hpp__HH		1

//	////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////
//	Include necessary header files . . .
//	////////////////////////////////////////////////////////////////////////////

#include <SocketIo/BoostAsioInclude.hpp>

#include <vector>

//	////////////////////////////////////////////////////////////////////////////

namespace MLB {

namespace SocketIo {

// ////////////////////////////////////////////////////////////////////////////
typedef boost::asio::ip::address IpAddressGeneric;
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
typedef std::vector<IpAddressGeneric>        IpAddressGenericList;
typedef IpAddressGenericList::iterator       IpAddressGenericListIter;
typedef IpAddressGenericList::const_iterator IpAddressGenericListIterC;
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
IpAddressGeneric ParseIpAddressFromString(const char *in_string,
	bool ipv6_ok = true, bool mc_ok = true, bool require_mc = false);
IpAddressGeneric ParseIpAddressFromString(const std::string &in_string,
	bool ipv6_ok = true, bool mc_ok = true, bool require_mc = false);
// ////////////////////////////////////////////////////////////////////////////

} // namespace SocketIo

} // namespace MLB

#endif // #ifndef HH__MLB__SocketIo__IpAddressGeneric_hpp__HH

