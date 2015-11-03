#ifndef BioProfile_Resource_INCLUDED
#define BioProfile_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
				
		class BioProfileResource : public BioControlResource <UInfoItem>
		{
		public:
			BioProfileResource();

			virtual ~BioProfileResource();

		private:
			void do_initialize();
		
		};

	}
}


#endif