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
			View::UInfoItem btn_enroll_from_camera  (	"", "You can edit properties", "resources\\face\\from_camera.png", "");
			View::UInfoItem btn_enroll_from_image   (	"", "You can edit properties", "resources\\face\\from_image.png" , "");
			View::UInfoItem btn_selected_face_delete( "", "You can edit properties", "resources\\face\\delete.png"     , "");
			View::UInfoItem selected_face           ( "", "You can edit properties", "resources\\face\\avatar.png"     , "");
			View::UInfoItem status_image					  ( "", "You can edit properties", "resources\\face\\status.png"     , "");

			insert(UIBioFacePage::ID_BTN_ENROLL_FROM_CAMERA, btn_enroll_from_camera  );
			insert(UIBioFacePage::ID_BTN_ENROLL_FROM_IMAGE , btn_enroll_from_image   );
			insert(UIBioFacePage::ID_BTN_FACE_DELETE       , btn_selected_face_delete);
			insert(UIBioFacePage::ID_PERSON_FACE_IMAGE     , selected_face           );
			insert(UIBioFacePage::ID_STATUS_IMAGE          , status_image            );
		}
	}
}