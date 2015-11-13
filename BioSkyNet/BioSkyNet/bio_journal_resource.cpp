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
			View::UInfoItem btn_delete   (""      , "Delete"    , "resources\\journal\\delete.png"    , "");
			View::UInfoItem btn_delet_all(""      , "Delete All", "resources\\journal\\delete_all.png", "");
			View::UInfoItem person_name        ("Person"             , "", "", "");
			View::UInfoItem location           ("Location"           , "", "", "");
			View::UInfoItem time               ("Time"               , "", "", "");
			View::UInfoItem photo              ("Photo"              , "", "", "");
			View::UInfoItem full_photo         ("Full photo"         , "", "", "");
			View::UInfoItem status             ("Status"             , "", "", "");
			View::UInfoItem detected_face_count("Detected face count", "", "", "");




			
			insert(UIBioJournalPage::ID_BTN_JOURNAL_DELETE          , btn_delete         );
			insert(UIBioJournalPage::ID_BTN_JOURNAL_DELETE_ALL      , btn_delet_all      );
			insert(UIBioJournalPage::ID_JOURNAL_PERSON_NAME         , person_name        );
			insert(UIBioJournalPage::ID_JOURNAL_LOCATION            , location           );
			insert(UIBioJournalPage::ID_JOURNAL_TIME                , time               );
			insert(UIBioJournalPage::ID_JOURNAL_PHOTO               , photo              );
			insert(UIBioJournalPage::ID_JOURNAL_FULL_PHOTO          , full_photo         );
			insert(UIBioJournalPage::ID_JOURNAL_STATUS              , status             );
			insert(UIBioJournalPage::ID_JOURNAL_DETECTED_FACE_COUNT , detected_face_count);




		}

	}
}