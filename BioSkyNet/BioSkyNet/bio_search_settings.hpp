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

			wxPropertyCategory* category_date_time_      ;
			wxEnumProperty*     property_date_from_      ;
			wxEnumProperty*     property_date_to_        ;
			wxEnumProperty*     property_only_today_     ;
			wxEnumProperty*     property_only_yesterday_ ;
			wxEnumProperty*     property_only_last_week_ ;
			wxEnumProperty*     property_only_last_month_;
		
			wxPropertyCategory* category_location_ ;
			wxEnumProperty*     property_locations_;
			
			wxPropertyCategory* category_person_information_;
			wxEnumProperty*     property_first_name_        ;
			wxEnumProperty*     property_last_name_         ;
			
			wxPropertyCategory* category_face_                   ;
			wxEnumProperty*     property_by_face_age_            ;
			wxEnumProperty*     property_by_face_image_          ;
			wxEnumProperty*     property_by_face_face_confidence_;
		};
	}
}

#endif


