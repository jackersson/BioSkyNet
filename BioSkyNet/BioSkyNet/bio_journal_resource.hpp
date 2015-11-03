#ifndef BioJournal_Resource_INCLUDED
#define BioJournal_Resource_INCLUDED

#include "uinfo_item.hpp"
#include "bio_control_resource.hpp"

namespace SmartBio
{
	namespace View
	{

		class BioJournalResource : public BioControlResource <UInfoItem>
		{
		public:
			BioJournalResource();

			virtual ~BioJournalResource();

		private:
			void do_initialize();

		};

	}
}


#endif