#pragma once

#ifndef BioDevice_Settings_INCLUDED
#define BioDevice_Settings_INCLUDED

namespace SmartBio
{
	namespace View
	{
		class BioDeviceSettings : public wxPropertyGridPage
		{

		public:
			BioDeviceSettings();
			~BioDeviceSettings();

		private:
			void do_initialize();

			wxEnumProperty* port_name_;
			wxEnumProperty* baud_rate_;
		};
	}
}

#endif


