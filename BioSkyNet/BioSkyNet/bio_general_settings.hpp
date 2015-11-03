#pragma once

#ifndef BioGeneral_Settings_INCLUDED
#define BioGeneral_Settings_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioGeneralSettings : public wxPropertyGridPage
		{

		public:
			BioGeneralSettings();
			~BioGeneralSettings();
					
		private:
			void do_initialize();

		};
	}
}

#endif


