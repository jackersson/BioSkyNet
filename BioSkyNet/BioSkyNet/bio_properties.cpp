#include "stdafx.h"
#include "bio_properties.hpp"

#include "Poco/RegularExpression.h"

namespace SmartBio
{
	namespace View
	{


		wxTextPropertyEx::wxTextPropertyEx(const wxString& label,
			                                 const wxString& name,
			                                 const wxString& value) 
																			 : wxStringProperty(label, name, value)
		{
		}

		wxTextPropertyEx::~wxTextPropertyEx()
		{

		}

		bool wxTextPropertyEx::ValidateValue(wxVariant& value, wxPGValidationInfo& validationInfo) const
		{
			Poco::RegularExpression exp_username_("^[a-zA-Z`\-]{2,}$");

			bool res;
			res = exp_username_.match(value.GetString().ToStdString());
			validationInfo.SetFailureMessage("Properties can include only characters and more then one");
			return res;
		}

		/*****************************************************************************************************/
		

			wxEmailPropertyEx::wxEmailPropertyEx(const wxString& label,
				                                   const wxString& name ,
				                                   const wxString& value ) 
				                                   : wxStringProperty(label, name, value)
			{
			}

			wxEmailPropertyEx::~wxEmailPropertyEx()
			{
			}

			bool wxEmailPropertyEx::ValidateValue(wxVariant& value, wxPGValidationInfo& validationInfo) const
			{
				Poco::RegularExpression exp_float_range("^[a-zA-Z0-9_\.]+@[a-zA-Z_]+?\.[a-zA-Z]{2,63}$");

				bool res;
				res = exp_float_range.match(value.GetString().ToStdString());
				if (!res)
					validationInfo.SetFailureMessage("Invalid email (Check for '@', '.')");
				return res;
			}
	}
}

