#pragma once

#ifndef BioFace_Settings_INCLUDED
#define BioFace_Settings_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioFaceSettings : public wxPropertyGridPage
		{

		public:
			BioFaceSettings();
			~BioFaceSettings();
		
		private:
			void do_initialize();

		private:
			wxEnumProperty* age_treshold_     ;
			wxEnumProperty* face_confidence_  ;
			wxEnumProperty* min_eye_distance_ ;
			wxEnumProperty* max_eye_distance_ ;
			wxEnumProperty* matching_treshold_;
		};
	}
}

#endif


