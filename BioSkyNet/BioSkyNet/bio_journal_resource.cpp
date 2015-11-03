#include "stdafx.h"
#include "bio_journal_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{
		BioJournalResource::BioJournalResource()
		{
			initialize();
		}

		BioJournalResource::~BioJournalResource()	{}

		void BioJournalResource::do_initialize()
		{
			View::UInfoItem btn_delete   ("", "Delete"    , "resources\\journal\\delete.png"    , "");
			View::UInfoItem btn_delet_all("", "Delete All", "resources\\journal\\delete_all.png", "");
			
			insert(UIBioJournalPage::ID_BTN_JOURNAL_DELETE    , btn_delete   );
			insert(UIBioJournalPage::ID_BTN_JOURNAL_DELETE_ALL, btn_delet_all);
		}

	}
}