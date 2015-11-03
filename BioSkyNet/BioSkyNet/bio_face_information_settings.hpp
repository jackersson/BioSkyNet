#pragma once

#ifndef BioFaceInformation_Settings_INCLUDED
#define BioFaceInformation_Settings_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioFaceInformationSettings : public wxPropertyGridPage
		{

		public:
			BioFaceInformationSettings();
			~BioFaceInformationSettings();


		private:
			void do_initialize();


		private:
			wxEnumProperty* number_of_faces_;
			wxEnumProperty* natural_skin_color_;
			wxEnumProperty* gender_;
			wxEnumProperty* age_;
			wxEnumProperty* glasses_;
			wxEnumProperty* resolution_;
			wxEnumProperty* ethnicity_;




		};
	}
}

#endif


