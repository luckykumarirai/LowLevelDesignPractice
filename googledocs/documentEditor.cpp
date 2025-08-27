#include <iostream>
#include <vector>
#include <string>
#include<fstream>

using namespace std;

// abstarct class for different elment type in documnt - text, image, table, highlight, syntaxt checke
class DocumentElement
{
public:
    virtual string render()=0;
};

// inherite by text amnd image class 
class Text : public DocumentElement{
    private : 
    string text;
    public:
        Text(string text)
        {
            this->text=text;
        }
     string render() override
     {
        return text;
     }
};

class Image: public DocumentElement{
    private: 
    string path;
    public: 
    Image(string path)
    {
        this->path=path;
    }
    string render ()override{
        return "[Image: "+path +"]";
    }
};

// abstarct class to save files 
class Persistance{
    public: 
        virtual void save(string data) = 0;
};
class SaveDB: public Persistance{
    public:
        void save(string data) override{
            cout <<"data save in database"<<endl;
        }
};
class SaveFile: public Persistance{
    public:
        void save(string data) override {
        ofstream outFile("document.txt");
        if (outFile) {
            outFile << data;
            outFile.close();
            cout << "Document saved to document.txt" << endl;
        } else {
            cout << "Error: Unable to open file for writing." << endl;
        }
    }
};


class Document{
    public: 
    // it hold all different elememnts;
    vector<DocumentElement*> elements;
    // to add all elements type
    void addElement(DocumentElement *ele)
    {
        elements.push_back(ele);
    }

    // to render all element by loopin on documentElement conatiner
    string render()
    {
        string result;
        for(auto ele: elements)
        {
            result += ele->render();
        }
        return result;
    }
};

class DocumentEditor{
    public:
        Document *doc;
        Persistance *store;
        string renderElements;
        DocumentEditor(Document *doc, Persistance *store)
        {
            this ->doc=doc;
            this->store=store;
        }
        void addText(string text)
        {
            doc->addElement(new Text(text));
        }
        void addImage(string path)
        {
            doc->addElement(new Image(path));
        }
        string render()
        {
            if(renderElements.empty())
            {
                renderElements+= doc->render();
            }
            return renderElements;
        }
        void save()
        {
            store->save(renderElements);
        }
};

int main()
{
    Persistance *db = new SaveFile();
    Document *doc = new Document();
    DocumentEditor * editor = new DocumentEditor(doc,db);
    editor->addText("hello lucky");
    editor->addImage("/home/Destop/lucky.jpeg");
    editor->render();
    editor->save();
    return 0;
}


