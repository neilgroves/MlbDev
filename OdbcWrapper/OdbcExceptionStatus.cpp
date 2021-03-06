// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
//	ODBC Wrapper Library Module
// ////////////////////////////////////////////////////////////////////////////
/*
	File Name			:	%M%

	File Version		:	%I%

	Last Extracted		:	%D%	%T%

	Last Updated		:	%E%	%U%

	File Description	:	Implementation of the OdbcExceptionStatus class.

	Revision History	:	2001-10-01 --- Creation.
									Michael L. Brock

		Copyright Michael L. Brock 2001 - 2014.
		Distributed under the Boost Software License, Version 1.0.
		(See accompanying file LICENSE_1_0.txt or copy at
		http://www.boost.org/LICENSE_1_0.txt)

*/
// ////////////////////////////////////////////////////////////////////////////

// ////////////////////////////////////////////////////////////////////////////
// ////////////////////////////////////////////////////////////////////////////
//	Required include files...
// ////////////////////////////////////////////////////////////////////////////

#include <OdbcWrapper/OdbcWrapper.hpp>

// ////////////////////////////////////////////////////////////////////////////

namespace MLB {

namespace OdbcWrapper {

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus()
	:OdbcException()
	,odbc_status_(SQL_SUCCESS)
	,function_args_()
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus(const char *except_string)
	:OdbcException(except_string)
	,odbc_status_(SQL_SUCCESS)
	,function_args_()
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus(const std::string &except_string)
	:OdbcException(except_string)
	,odbc_status_(SQL_SUCCESS)
	,function_args_()
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus(
	const std::ostringstream &except_string)
	:OdbcException(except_string)
	,odbc_status_(SQL_SUCCESS)
	,function_args_()
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus(SQLRETURN odbc_status)
	:OdbcException(GetStatusString(odbc_status))
	,odbc_status_(odbc_status)
	,function_args_()
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus(SQLRETURN odbc_status,
	const char *except_string, const char *function_args)
	:OdbcException(GetStatusString(odbc_status, except_string))
	,odbc_status_(odbc_status)
	,function_args_((function_args != NULL) ? function_args : "")
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus(SQLRETURN odbc_status,
	const std::string &except_string, const char *function_args)
	:OdbcException(GetStatusString(odbc_status, except_string.c_str()))
	,odbc_status_(odbc_status)
	,function_args_((function_args != NULL) ? function_args : "")
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::OdbcExceptionStatus(SQLRETURN odbc_status,
	const std::ostringstream &except_string, const char *function_args)
	:OdbcException(GetStatusString(odbc_status, except_string.str().c_str()))
	,odbc_status_(odbc_status)
	,function_args_((function_args != NULL) ? function_args : "")
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
OdbcExceptionStatus::~OdbcExceptionStatus()
{
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
SQLRETURN OdbcExceptionStatus::GetStatus() const
{
	return(odbc_status_);
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
std::string OdbcExceptionStatus::GetFunctionArgs() const
{
	return(function_args_);
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
void OdbcExceptionStatus::Rethrow(const char *except_string) const
{
	OdbcExceptionStatus tmp_except(*this);

	tmp_except.SetWhat(except_string);

	throw tmp_except;
}
//	////////////////////////////////////////////////////////////////////////////

//	////////////////////////////////////////////////////////////////////////////
std::string OdbcExceptionStatus::GetStatusString(SQLRETURN odbc_status,
	const char *other_text)
{
	std::ostringstream status_string;

	status_string << "OdbcWrapper exception resulted from status " <<
		"code = " << odbc_status << ", " <<
		((other_text != NULL) ? ": " : "") <<
		((other_text != NULL) ? other_text : ".");

	return(status_string.str());
}
//	////////////////////////////////////////////////////////////////////////////

} // namespace OdbcWrapper

} // namespace MLB

