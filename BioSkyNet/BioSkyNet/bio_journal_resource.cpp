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


			// 			std::string tjournal = "Journal";
			// 			std::string tjournal_hint = "Journal";
			// 			std::string tjournal_icon = "resources\\toolbar\\journalx48.png";

			View::UInfoItem btn_delete("", "Delete", "resources\\journal\\delete.png", "");
			View::UInfoItem btn_delet_all("", "Delete All", "resources\\journal\\delete_all.png", "");




			/*View::UInfoItem journal(tjournal, tjournal_hint, tjournal_icon, "");*/

			insert(UIBioJournalPage::ID_BTN_JOURNAL_DELETE    , btn_delete);
			insert(UIBioJournalPage::ID_BTN_JOURNAL_DELETE_ALL, btn_delet_all);




		}

	}
}