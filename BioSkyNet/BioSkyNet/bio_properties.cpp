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




			wxAgeTresholdPropertyEx::wxAgeTresholdPropertyEx(const wxString& label,
				const wxString& name
				)
				: wxIntProperty(label, name)				
			{
			}

			wxAgeTresholdPropertyEx::~wxAgeTresholdPropertyEx()
			{
			}

			bool wxAgeTresholdPropertyEx::ValidateValue(wxVariant& value, wxPGValidationInfo& validationInfo) const
			{
				Poco::RegularExpression exp_int_range("^(1[4-9]|[2-9][0-9]|100)$");

				bool res;
				res = exp_int_range.match(value.GetString().ToStdString());
				if (!res)
					validationInfo.SetFailureMessage("Property can include only range of 14-100");
				return res;
			}


			wxFaceConfidencePropertyEx::wxFaceConfidencePropertyEx(const wxString& label,
				const wxString& name
				)
				: wxFloatProperty(label, name)
			{
			}

			wxFaceConfidencePropertyEx::~wxFaceConfidencePropertyEx()
			{
			}

			bool wxFaceConfidencePropertyEx::ValidateValue(wxVariant& value, wxPGValidationInfo& validationInfo) const
			{
				Poco::RegularExpression exp_float_range("^ (0(. | , )[1 - 9]{1, 2} | [1 - 4](. | , )[0 - 9]{1, 2})$");

				bool res;
				res = exp_float_range.match(value.GetString().ToStdString());
				if (!res)
					validationInfo.SetFailureMessage("Property can include only range of 0 - 5)");
				return res;
			}



	}
}

