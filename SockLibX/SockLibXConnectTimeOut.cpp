//	////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////
//	SockLibX Portable Socket Library Source Module
//	////////////////////////////////////////////////////////////////////////////
/*
	File Name  			:	%M%

	File Version      :	%I%

	Last Extracted		:	%D%	%T%

	Last Updated		:	%E%	%U%

	File Description	:	Implementation of the SockLibXConnectTimeOut class.

	Revision History	:	2002-01-26 --- Creation
									Michael L. Brock

		Copyright Michael L. Brock 2002 - 2014.
		Distributed under the Boost Software License, Version 1.0.
		(See accompanying file LICENSE_1_0.txt or copy at
		http://www.boost.org/LICENSE_1_0.txt)

*/
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////
//	Include necessary header files . . .
//	////////////////////////////////////////////////////////////////////////////

#include <SockLibX.hpp>

//	////////////////////////////////////////////////////////////////////////////

namespace MLB {

namespace SockLibX {

//	////////////////////////////////////////////////////////////////////////////
SockLibXConnectTimeOut::SockLibXConnectTimeOut(const EndPointIP &endpoint,
	const char *except_string, SocketErrorCode error_code)
	:SockLibXConnectFailure(endpoint,
		GetStatusString(&endpoint, except_string), error_code)
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
SockLibXConnectTimeOut::~SockLibXConnectTimeOut() MBCOMPAT_EXCEPT_NOTHROW
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
void SockLibXConnectTimeOut::Rethrow(const char *except_string) const
{
	SockLibXConnectTimeOut tmp_except(*this);

	tmp_except.SetWhat(except_string);

	throw tmp_except;
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
std::string SockLibXConnectTimeOut::GetStatusString(
	const EndPointIP *endpoint_ptr, const char *other_text)
{
	return(std::string(SockLibXConnectFailure::GetStatusString(
		endpoint_ptr, other_text) + ": Connection timed-out."));
}
//	////////////////////////////////////////////////////////////////////////////

} // namespace SockLibX

} // namespace MLB

