#include "stdafx.h"
#include "bio_face_resource.hpp"

#include "bio_resources.hpp"

namespace SmartBio
{
	namespace View
	{

		BioFaceResource::BioFaceResource()
		{
			initialize();
		}

		BioFaceResource::~BioFaceResource()	{}

		void BioFaceResource::do_initialize()
		{
			View::UInfoItem btn_enroll_from_camera  (	"", "Enroll from camera"     , "resources\\face\\from_camera.png", "");
			View::UInfoItem btn_enroll_from_image   (	"", "Enroll from image"      , "resources\\face\\from_image.png" , "");
			View::UInfoItem btn_selected_face_delete( "", "Selected face delete"   , "resources\\face\\delete.png"     , "");
			View::UInfoItem selected_face           ( "", "You can edit properties", "resources\\face\\avatar.png"     , "");
			View::UInfoItem status_image					  ( "", "You can edit properties", "resources\\face\\status.png"     , "");

			View::UInfoItem first_name("Name"          , "", "", "");
			View::UInfoItem photo_path("Photo path"    , "", "", "");




			insert(UIBioFacePage::ID_FACE_PAGE_NAME      , first_name);
			insert(UIBioFacePage::ID_FACE_PAGE_PHOTO_PATH, photo_path);


			insert(UIBioFacePage::ID_BTN_ENROLL_FROM_CAMERA, btn_enroll_from_camera  );
			insert(UIBioFacePage::ID_BTN_ENROLL_FROM_IMAGE , btn_enroll_from_image   );
			insert(UIBioFacePage::ID_BTN_FACE_DELETE       , btn_selected_face_delete);
			insert(UIBioFacePage::ID_PERSON_FACE_IMAGE     , selected_face           );
			insert(UIBioFacePage::ID_STATUS_IMAGE          , status_image            );


			View::UInfoItem number_of_faces   ("Number of faces"   , "", "", "");
			View::UInfoItem natural_skin_color("Natural skin color", "", "", "");
			View::UInfoItem gender            ("Gender"            , "", "", "");
			View::UInfoItem age               ("Age"               , "", "", "");
			View::UInfoItem glasses           ("Glasses"           , "", "", "");
			View::UInfoItem resolution        ("Resolution"        , "", "", "");
			View::UInfoItem ethnicity         ("Ethnicity"         , "", "", "");
			View::UInfoItem sample_quality    ("Sample quality"    , "", "", "");


			insert(UIBioFacePage::ID_FACE_NUMBER_OF_FACES   , number_of_faces   );
			insert(UIBioFacePage::ID_FACE_NATURAL_SKIN_COLOR, natural_skin_color);
			insert(UIBioFacePage::ID_FACE_GENDER            , gender            );
			insert(UIBioFacePage::ID_FACE_AGE               , age               );
			insert(UIBioFacePage::ID_FACE_GLASSES           , glasses           );
			insert(UIBioFacePage::ID_FACE_RESOLURION        , resolution        );
			insert(UIBioFacePage::ID_FACE_ETHNICITY         , ethnicity         );
			insert(UIBioFacePage::ID_FACE_SAMPLE_QUALITY    , sample_quality    );

		}				 
	}					 
}						 