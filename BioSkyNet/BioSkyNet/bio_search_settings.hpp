#pragma once

#ifndef BioSearch_Settings_INCLUDED
#define BioSearch_Settings_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioSearchSettings : public wxPropertyGridPage
		{

		public:
			BioSearchSettings();
			~BioSearchSettings();


		private:
			void do_initialize();


		private:

			wxPropertyCategory* date_time_;
			wxEnumProperty* date_from_;
			wxEnumProperty* date_to_;
			wxEnumProperty* today_;
			wxEnumProperty* yesterday_;
			wxEnumProperty* last_week_;
			wxEnumProperty* last_month_;
		
			wxPropertyCategory* location_;
			wxEnumProperty* locations_;
			
			wxPropertyCategory* person_information_;
			wxEnumProperty* firs_name_;
			wxEnumProperty* last_name_;
			
			wxPropertyCategory* by_face_;
			wxEnumProperty* by_face_age_;
			wxEnumProperty* by_face_image_;
			wxEnumProperty* by_face_face_confidence_;







		};
	}
}

#endif


