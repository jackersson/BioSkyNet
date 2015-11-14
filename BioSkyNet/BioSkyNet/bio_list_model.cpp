
#include "stdafx.h"

#include "bio_list_model.hpp"




namespace SmartBio
{
	namespace View
	{
		MyListModel::MyListModel(std::vector<Data::BioPerson> data) :
			wxDataViewVirtualListModel(data.size())
		{
			// the first 100 items are really stored in this model;
			// all the others are synthesized on request
/*    
			static const unsigned NUMBER_REAL_ITEMS = 100;

			m_textColValues.reserve(NUMBER_REAL_ITEMS);
			m_textColValues.push_back("first row with long label to test ellipsization");
			for (unsigned int i = 1; i < NUMBER_REAL_ITEMS; i++)
			{
				m_textColValues.push_back(wxString::Format("real row %d", i));
			}*/

			/*	m_iconColValues.assign(NUMBER_REAL_ITEMS, "test");*/

			/*	m_icon[0] = wxIcon(null_xpm);
			m_icon[1] = wxIcon(wx_small_xpm);*/

			vec_data = data;
			
			
		}


		MyListModel::~MyListModel()
		{

		}

		void MyListModel::Prepend(const wxString &text)
		{
			m_textColValues.Insert(text, 0);
			RowPrepended();
		}

		void MyListModel::DeleteItem(const wxDataViewItem &item)
		{
			unsigned int row = GetRow(item);

			if (row >= m_textColValues.GetCount())
				return;

			m_textColValues.RemoveAt(row);
			RowDeleted(row);
		}

		void MyListModel::DeleteItems(const wxDataViewItemArray &items)
		{
			unsigned i;
			wxArrayInt rows;
			for (i = 0; i < items.GetCount(); i++)
			{
				unsigned int row = GetRow(items[i]);
				if (row < m_textColValues.GetCount())
					rows.Add(row);
			}

			if (rows.GetCount() == 0)
			{
				// none of the selected items were in the range of the items
				// which we store... for simplicity, don't allow removing them
				wxLogError("Cannot remove rows with an index greater than %d", m_textColValues.GetCount());
				return;
			}

			// Sort in descending order so that the last
			// row will be deleted first. Otherwise the
			// remaining indeces would all be wrong.
			
			for (i = 0; i < rows.GetCount(); i++)
				m_textColValues.RemoveAt(rows[i]);

			// This is just to test if wxDataViewCtrl can
			// cope with removing rows not sorted in
			// descending order
		
			RowsDeleted(rows);
		}

		void MyListModel::AddMany()
		{
			Reset(GetCount() + 1000);
		}

		void MyListModel::GetValueByRow(wxVariant &variant,
			unsigned int row, unsigned int col) const
		{
			switch (col)
			{

					case Col_EditableText:
				if (row >= m_textColValues.GetCount())
				variant = wxString::Format("virtual row %d", row);

				else
					variant = m_textColValues[row];
				break;

					case Col_FirstName:
						if (row <= vec_data.size())
						{							
							variant = vec_data[row].firstName();
						}

						break;

					case Col_LastName:
						if (row <= vec_data.size())
						{
							variant = vec_data[row].lastName();
						}

						break;		

					case Col_DateOfBirth:
						if (row <= vec_data.size())
						{

							Poco::DateTime birthday = vec_data[row].dateOfBirth();
							wxDateTime wx_date_time;
							wx_date_time.SetYear(birthday.year());
							wx_date_time.SetMonth((wxDateTime::Month)birthday.month());
							wx_date_time.SetDay(birthday.day());
							variant = wx_date_time;
						}

						break;

					case Col_Gender:
						if (row <= vec_data.size())
						{
							wxVariant g = vec_data[row].gender();
							variant = g;
						}

						break;

					case Col_Country:
						if (row <= vec_data.size())
						{
							variant = vec_data[row].country();
						}

						break;

					case Col_City:
						if (row <= vec_data.size())
						{
							variant = vec_data[row].city();
						}

						break;	

					case Col_Avatar:
						if (row <= vec_data.size())
						{
							wxString imagestr = vec_data[row].avatar();
							if (wxFileName::FileExists(imagestr))
							{
								wxImage image = vec_data[row].avatar();
								image.Rescale(128, 128);
								wxBitmap bitmap(image, wxBITMAP_TYPE_BMP);
								variant << image;
							}
							else
								variant << wxArtProvider::GetBitmap(wxART_ERROR);
							
						}

						break;

					case Col_Email:
						if (row <= vec_data.size())
						{
							variant = vec_data[row].email();
						}

						break;

					case Col_Comments:
						if (row <= vec_data.size())
						{
							variant = vec_data[row].comments();
						}

						break;

					case Col_Rights:
						if (row <= vec_data.size())
						{
							wxVariant r = vec_data[row].gender();

							variant = r;
						}

						break;

/*
					case Col_FirstName:
				if (row >= m_textColValues.GetCount())
			  variant = wxString::Format("first name %d", row);

				else
				variant = m_textColValues[row];
				break;*/

			case Col_IconText:
			{
				/*wxString text;
				if (row >= m_iconColValues.GetCount())
				text = "virtual icon";
				else
				text = m_iconColValues[row];*/
				wxImage im("1.bmp");
				if (im.IsOk())
				{
					im.Rescale(128, 128);
					wxBitmap bitmap(im, wxBITMAP_TYPE_BMP);
					variant << bitmap;
				}
				/*				wxBitmap bitmap(im, wxBITMAP_TYPE_BMP);
				bitmap.SetSize(wxSize(32, 32));
				variant << bitmap;
				*/

				//variant << wxDataViewIconText(text, m_icon[row % 2]);
			}
			break;

			/*case Col_TextWithAttr:
			{
			static const char *labels[5] =
			{
			"blue", "green", "red", "bold cyan", "default",
			};

			variant = labels[row % 5];
			}
			break;

			case Col_Custom:
			variant = wxString::Format("%d", row % 100);
			break;
			*/

			case Col_Max:
				wxFAIL_MSG("invalid column");
			}
		}

		bool MyListModel::GetAttrByRow(unsigned int row, unsigned int col,
			wxDataViewItemAttr &attr) const
		{
			switch (col)
			{
				/*case Col_EditableText:
				return false;*/

			case Col_IconText:
				if (!(row % 2))
					return false;
				attr.SetColour(*wxLIGHT_GREY);
				break;

				/*	case Col_TextWithAttr:
				case Col_Custom:
				// do what the labels defined in GetValueByRow() hint at
				switch (row % 5)
				{
				case 0:
				attr.SetColour(*wxBLUE);
				break;

				case 1:
				attr.SetColour(*wxGREEN);
				break;

				case 2:
				attr.SetColour(*wxRED);
				break;

				case 3:
				attr.SetColour(*wxCYAN);
				attr.SetBold(true);
				break;

				case 4:
				return false;
				}
				break;*/

			case Col_Max:
				wxFAIL_MSG("invalid column");
			}

			return true;
		}

		bool MyListModel::SetValueByRow(const wxVariant &variant,
			unsigned int row, unsigned int col)
		{
			switch (col)
			{
				case Col_EditableText:
			case Col_IconText:
				if (row >= m_textColValues.GetCount())
				{
					// the item is not in the range of the items
					// which we store... for simplicity, don't allow editing it
					wxLogError("Cannot edit rows with an index greater than %d",
						m_textColValues.GetCount());
					return false;
				}

					if (col == Col_EditableText)
				{
				m_textColValues[row] = variant.GetString();
				}
				else // col == Col_IconText
				{
				wxDataViewIconText iconText;
				iconText << variant;
				m_iconColValues[row] = iconText.GetText();
				}
				return true;

				/*case Col_TextWithAttr:
				case Col_Custom:
				wxLogError("Cannot edit the column %d", col);
				break;
				*/

			case Col_Max:
				wxFAIL_MSG("invalid column");
			}

			return false;
		};

	   unsigned int MyListModel::GetColumnCount() const
		{
			return Col_Max;
		};

		 wxString MyListModel::GetColumnType(unsigned int col) const
		 {
			 if (col == Col_IconText)
				 return wxT("bitmap");
			 //return wxT("wxDataViewIconText");

			 return wxT("string");
		 };
	}
}