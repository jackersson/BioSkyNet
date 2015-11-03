#ifndef BioSurveillance_Resource_INCLUDED
#define BioSurveillance_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{

		class BioSurveillanceResource : public BioControlResource <UInfoItem>
		{
		public:
			BioSurveillanceResource();

			virtual ~BioSurveillanceResource();

		private:
			void do_initialize();

		};

	}
}


#endif