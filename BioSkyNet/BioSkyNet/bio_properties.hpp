#ifndef Bio_Properties_INCLUDED
#define Bio_Properties_INCLUDED

//For property values validation after changing them

namespace SmartBio
{
	namespace View
	{
		class wxTextPropertyEx : public wxStringProperty
		{
		public:
			wxTextPropertyEx(const wxString& label = wxPG_LABEL,
				               const wxString& name = wxPG_LABEL,
				               const wxString& value = wxEmptyString);
		

			~wxTextPropertyEx();
		

			bool ValidateValue(wxVariant& value, wxPGValidationInfo& validationInfo) const;

		};

		class wxEmailPropertyEx : public wxStringProperty
		{
		public:
			wxEmailPropertyEx(const wxString& label = wxPG_LABEL,
				                const wxString& name = wxPG_LABEL,
				                const wxString& value = wxEmptyString);

				~wxEmailPropertyEx();		

				bool ValidateValue(wxVariant& value, wxPGValidationInfo& validationInfo) const;

		};

	}
}
#endif