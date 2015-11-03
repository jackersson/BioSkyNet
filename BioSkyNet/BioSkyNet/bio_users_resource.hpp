#ifndef BioUsers_Resource_INCLUDED
#define BioUsers_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{

		class BioUsersResource : public BioControlResource <UInfoItem>
		{
		public:
			BioUsersResource();

			virtual ~BioUsersResource();

		private:
			void do_initialize();

		};

	}
}


#endif