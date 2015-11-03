#ifndef BioFace_Resource_INCLUDED
#define BioFace_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{

		class BioFaceResource : public BioControlResource <UInfoItem>
		{
		public:
			BioFaceResource();

			virtual ~BioFaceResource();

		private:
			void do_initialize();

		};

	}
}


#endif