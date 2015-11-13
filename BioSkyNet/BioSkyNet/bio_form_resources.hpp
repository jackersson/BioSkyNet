#ifndef BioForm_Resources_INCLUDED
#define BioForm_Resources_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{
		class BioFormResource : public BioControlResource<UInfoItem>
		{
		public:
			BioFormResource();
			virtual ~BioFormResource();			

		private:
			void do_initialize();
		};
	}
}
#endif