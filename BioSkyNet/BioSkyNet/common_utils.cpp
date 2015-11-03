#include "stdafx.h"
#include "common_utils.hpp"

namespace SmartBio
{
	namespace View
	{
		
		CommonUtils::CommonUtils()
		{

		}

		CommonUtils::~CommonUtils()
		{
		}

		wxCommandLinkButton* CommonUtils::addCommandLinkButton(int index, wxWindow* parent
			                                                    , BioControlResource<UInfoItem>& resource
																												  , wxSizer* sizer)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxCommandLinkButton* btn = new wxCommandLinkButton(parent, wxID_ANY, item.text(), item.hint());
				sizer->Add(btn, 1, 0, 5);
				return NULL;
			}
			return NULL;
		}

		wxBitmapButton* CommonUtils::addButton( int index, wxWindow* parent
			                                    , BioControlResource<UInfoItem>& resource
																					, wxSizer* sizer
																					, int style)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxBitmapButton* btn = new wxBitmapButton( parent, wxID_ANY, item.bitmap() );
				sizer->Add( btn, 1, style, 5 );
				return btn;
			}
			return NULL;
		}

		wxStaticBitmap* CommonUtils::addImage(int index, wxWindow* parent
				                                      , BioControlResource<UInfoItem>& resource
				                                      , wxSizer* sizer, int style)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxStaticBitmap* img = new wxStaticBitmap(parent, wxID_ANY, item.bitmap() );

				sizer->Add(img, 1, style, 5);

				return img;
			}
			return NULL;
		}

		void CommonUtils::addSettingsPage( int index, wxPropertyGridManager& pages_manager
			                               , BioControlResource<UInfoItem>& resource, wxPropertyGridPage* page)
		{
			bool result(false);
			UInfoItem item = resource.get(index, result);

			if (result)
			{
				pages_manager.AddPage(item.text(), item.bitmap(), page);
			}
		}

		wxStaticText* CommonUtils::addText( int index, wxWindow* parent
			                                , BioControlResource<UInfoItem>& resource
			                                , wxSizer* sizer, int style)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);

			if (flag)
			{
				wxStaticText* txt = new wxStaticText(parent, wxID_ANY, item.text() );
				sizer->Add(txt, 1, style, 5);
				return txt;
			}

			return NULL;
		}

		void CommonUtils::fillBitmapFromResource( int index, wxBitmap& parent
			                                      , BioControlResource<UInfoItem>& resource)
		{
			bool flag(false);
			View::UInfoItem item = resource.get(index, flag);
			if (flag)
				parent = item.bitmap();
		}


	}
}
