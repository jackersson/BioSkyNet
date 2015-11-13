/*
#ifndef Bio_List_Model_INCLUDED
#define Bio_List_Model_INCLUDED


namespace SmartBio
{
	namespace View
	{

		class MyListModel : public wxDataViewVirtualListModel
		{
		public:
			enum
			{
				/ *Col_EditableText,* /
				Col_IconText,
				/ *		Col_TextWithAttr,
				Col_Custom,* /
				Col_Max
			};

			MyListModel();
			~MyListModel();


			// helper methods to change the model

			void Prepend(const wxString &text);
			void DeleteItem(const wxDataViewItem &item);
			void DeleteItems(const wxDataViewItemArray &items);
			void AddMany();


			// implementation of base class virtuals to define model

			virtual unsigned int GetColumnCount() const
			{
				return Col_Max;
			}

			virtual wxString GetColumnType(unsigned int col) const
			{
				if (col == Col_IconText)
					return wxT("bitmap");
				//return wxT("wxDataViewIconText");

				return wxT("string");
			}

			virtual void GetValueByRow(wxVariant &variant,
				unsigned int row, unsigned int col) const;
			virtual bool GetAttrByRow(unsigned int row, unsigned int col,
				wxDataViewItemAttr &attr) const;
			virtual bool SetValueByRow(const wxVariant &variant,
				unsigned int row, unsigned int col);

		private:
			wxArrayString    m_textColValues;
			wxArrayString    m_iconColValues;
			wxIcon           m_icon[2];
		};

		class MyCustomRenderer : public wxDataViewCustomRenderer
		{
		public:
			MyCustomRenderer()
				: wxDataViewCustomRenderer("string",
				wxDATAVIEW_CELL_ACTIVATABLE,
				wxALIGN_CENTER)
			{ }

			virtual bool Render(wxRect rect, wxDC *dc, int state)
			{
				dc->SetBrush(*wxLIGHT_GREY_BRUSH);
				dc->SetPen(*wxTRANSPARENT_PEN);

				rect.Deflate(2);
				dc->DrawRoundedRectangle(rect, 5);

				RenderText(m_value,
					0, // no offset
					wxRect(dc->GetTextExtent(m_value)).CentreIn(rect),
					dc,
					state);
				return true;
			}

			virtual bool ActivateCell(const wxRect& WXUNUSED(cell),
				wxDataViewModel *WXUNUSED(model),
				const wxDataViewItem &WXUNUSED(item),
				unsigned int WXUNUSED(col),
				const wxMouseEvent *mouseEvent)
			{
				wxString position;
				if (mouseEvent)
					position = wxString::Format("via mouse at %d, %d", mouseEvent->m_x, mouseEvent->m_y);
				else
					position = "from keyboard";
				wxLogMessage("MyCustomRenderer ActivateCell() %s", position);
				return false;
			}

			virtual wxSize GetSize() const
			{
				return wxSize(60, 20);
			}

			virtual bool SetValue(const wxVariant &value)
			{
				m_value = value.GetString();
				return true;
			}

			virtual bool GetValue(wxVariant &WXUNUSED(value)) const { return true; }

		private:
			wxString m_value;
		};

	}
}


#endif
*/
