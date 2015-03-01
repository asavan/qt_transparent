#include <QObject>
class BassLib;

class MyClass : public QObject
{
    Q_OBJECT
public:
    MyClass();
    ~MyClass();
public slots:
    void getData(int k);
private :
    MyClass(const MyClass&);
    MyClass& operator=(const MyClass&);
	int music_prepare(int key);
	BassLib* pl;
};
