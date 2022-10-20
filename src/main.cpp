#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

class BodyInfo
{
public:
	unsigned char blue;
	unsigned char green;
	unsigned char red;
public:

	BodyInfo(unsigned char blue = '0', unsigned char green = '0', unsigned char red = '0')
	{
		this->blue = blue;
		this->green = green;
		this->red = red;
	}

	unsigned char GetBlue()
	{
		return blue;
	}
	unsigned char GetGreen()
	{
		return green;
	}
	unsigned char GetRed()
	{
		return red;
	}
};
class HeaderInfo
{
public:
	unsigned char idLength;
	unsigned char colorMapType;
	unsigned char imageType;
	short colorMapOrigin;
	short colorMapLength;
	unsigned char colorMapDepth;
	short xOrigin;
	short yOrigin;
	short imageWidth;
	short imageHeight;
	unsigned char pixelDepth;
	unsigned char imageDescriptor;
	vector<BodyInfo> body;
	
public:
	HeaderInfo(unsigned char idLength = 0, unsigned char colorMapType = 0, unsigned char imageType = 0, short colorMapOrigin = 0, short colorMapLength = 0, unsigned char colorMapDepth = 0, short xOrigin = 0, short yOrigin = 0, short imageWidth = 0, short imageHeight = 0, unsigned char pixelDepth = 0, unsigned char imageDescriptor = 0)
	{	
		this->idLength = idLength;
		this->colorMapType = colorMapType;
		this->imageType = imageType;
		this->colorMapOrigin = colorMapOrigin;
		this->colorMapLength = colorMapLength;
		this->colorMapDepth = colorMapDepth;
		this->xOrigin = xOrigin;
		this->yOrigin = yOrigin;
		this->imageWidth = imageWidth;
		this->imageHeight = imageHeight;
		this->pixelDepth = pixelDepth;
		this->imageDescriptor = imageDescriptor;
	}
	unsigned char GetIdLength()
   {
	   return idLength;
   }
	unsigned char GetColorMapType()
   {
	   return colorMapType;
   }
	unsigned char GetImageType()
   {
	   return imageType;
   }
   short GetColorMapOrigin()
   {
	   return colorMapOrigin;
   }
   short GetColorMapLength()
   {
	   return colorMapLength;
   }
   unsigned char GetColorMapDepth()
   {
	   return colorMapDepth;
   }
   short GetXOrigin()
   {
	   return xOrigin;
   }
   short GetYOrigin()
   {
	   return yOrigin;
   }
   short GetImageWidth()
   {
	   return imageWidth;
   }
   short GetImageHeight()
   {
	   return imageHeight;
   }
   unsigned char GetPixelDepth()
   {
	   return pixelDepth;
   }
   unsigned char GetImageDescriptor()
   {
	   return imageDescriptor;
   }
  vector<BodyInfo>& GetBody()
   {
	   return body;
   }
};


void openfile(string path, vector<HeaderInfo>& header, vector<BodyInfo>& body);
void shipfile(string path, vector<HeaderInfo>& header, vector<BodyInfo>& body);
void Multiply(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header);
void Subtract(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header);
void Screen(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header);
void Overlay(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header);
void Green200(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header);
void Red4Blue0(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header);
void SeparateChannels(vector<BodyInfo>& returnVector, vector<BodyInfo>& returnVector1, vector<BodyInfo>& returnVector2, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header);
void CombineChannels(vector<BodyInfo>& returnVector, vector<BodyInfo>& returnVector1, vector<BodyInfo>& returnVector2, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header);
void ExtraCredit(vector<BodyInfo>& text, vector<BodyInfo>& swirls, vector<BodyInfo>& car, vector<BodyInfo>& circles, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header);
void shipfile1(string path, vector<HeaderInfo>& header, vector<BodyInfo>& body);
//void testfiles(vector<BodyInfo>& bottomLayer, vector<BodyInfo>& TopLayer);
int main()
{
	//vector<HeaderInfo> testheader1;
	//vector<HeaderInfo> testheader2;
	//vector<BodyInfo>  testbody1;
	//vector<BodyInfo> testbody2;

	//MULTIPLY FUNCTIONALITY
	vector<HeaderInfo> header;
	vector<BodyInfo> TopLayer;
	openfile("./input/layer1.tga", header, TopLayer);
	//shipfile("./output/writtendata.tga", header, body);

	vector<HeaderInfo> header1;
	vector<BodyInfo> BottomLayer;
	vector<BodyInfo> returnVector;
	vector<HeaderInfo> header2;
	vector<BodyInfo> returnVector1;
	vector<HeaderInfo> header3;
	vector<BodyInfo> returnVector2;
	vector<HeaderInfo> header4;
	openfile("./input/pattern1.tga", header1, BottomLayer);
	Multiply(returnVector, TopLayer, BottomLayer, header);
	shipfile("./output/part1.tga", header, returnVector);
	header.clear();
	TopLayer.clear();
	header1.clear();
	BottomLayer.clear();
	returnVector.clear();

	//cout << "Part 1 is: ";
	//openfile("./output/part1.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part1.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//SUBTRACTION FUNCTIONALITY
	openfile("./input/layer2.tga", header, TopLayer);
	openfile("./input/car.tga", header1, BottomLayer);
	Subtract(returnVector, TopLayer, BottomLayer, header);
	shipfile("./output/part2.tga", header, returnVector);
	header.clear();
	TopLayer.clear();
	header1.clear();
	BottomLayer.clear();
	returnVector.clear();

	//cout << "Part 2 is: ";
	//openfile("./output/part2.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part2.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//MULTIPLICATION FUNCTIONALITY AND SCREEN FUNCTIONALITY
	openfile("./input/layer1.tga", header, TopLayer);
	openfile("./input/pattern2.tga", header1, BottomLayer);
	Multiply(returnVector, TopLayer, BottomLayer, header);
	TopLayer.clear();
	header.clear();
	BottomLayer.clear();
	header1.clear();
	openfile("./input/text.tga", header, TopLayer);
	Screen(BottomLayer, TopLayer, returnVector, header);
	shipfile("./output/part3.tga", header, BottomLayer);
	header.clear();
	TopLayer.clear();
	header1.clear();
	BottomLayer.clear();
	returnVector.clear();

	//cout << "Part 3 is: ";
	//openfile("./output/part3.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part3.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//MULTIPLICATION AND SUBTRACTION FUNCTIONALITY
	openfile("./input/layer2.tga", header, TopLayer);
	openfile("./input/circles.tga", header1, BottomLayer);
	Multiply(returnVector, TopLayer, BottomLayer, header);
	header.clear();
	TopLayer.clear();
	header1.clear();
	BottomLayer.clear();
	openfile("./input/pattern2.tga", header, TopLayer);
	Subtract(BottomLayer, TopLayer, returnVector, header);
	shipfile("./output/part4.tga", header, BottomLayer);
	header.clear();
	TopLayer.clear();
	header1.clear();
	BottomLayer.clear();
	returnVector.clear();

	//cout << "Part 4 is: ";
	//openfile("./output/part1.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part1.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//Overlay Functionality
	openfile("./input/layer1.tga", header, TopLayer);
	openfile("./input/pattern1.tga", header1, BottomLayer);
	Overlay(returnVector, TopLayer, BottomLayer, header);
	shipfile("./output/part5.tga", header, returnVector);
	header.clear();
	TopLayer.clear();
	header1.clear();
	BottomLayer.clear();
	returnVector.clear();

	//cout << "Part 5 is: ";
	//openfile("./output/part5.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part5.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	// Green Channel Functionality
	openfile("./input/car.tga", header, TopLayer);
	Green200(returnVector, TopLayer, header);
	shipfile("./output/part6.tga", header, returnVector);
	header.clear();
	TopLayer.clear();
	returnVector.clear();

	//cout << "Part 6 is: ";
	//openfile("./output/part6.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part6.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//Red x 4 and Blue x 0 Functionality
	openfile("./input/car.tga", header, TopLayer);
	Red4Blue0(returnVector, TopLayer, header);
	shipfile("./output/part7.tga", header, returnVector);
	header.clear();
	TopLayer.clear();
	returnVector.clear();

	//cout << "Part 7 is: ";
	//openfile("./output/part7.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part7.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//Separate channels Functionality
	openfile("./input/car.tga", header, TopLayer);

	SeparateChannels(returnVector, returnVector1, returnVector2, TopLayer, header);
	shipfile("./output/part8_b.tga", header, returnVector);
	shipfile("./output/part8_g.tga", header, returnVector1);
	shipfile("./output/part8_r.tga", header, returnVector2);
	header.clear();
	TopLayer.clear();
	returnVector.clear();
	returnVector1.clear();
	returnVector2.clear();

	//cout << "Part 8 is: ";
	//openfile("./output/part8_b.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part8_b.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//openfile("./output/part8_g.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part8_g.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//openfile("./output/part8_r.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part8_r.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();

	//Combine channels Functionality
	openfile("./input/layer_red.tga", header, returnVector);
	openfile("./input/layer_green.tga", header1, returnVector1);
	openfile("./input/layer_blue.tga", header2, returnVector2);
	CombineChannels(returnVector, returnVector1, returnVector2, TopLayer, header);
	shipfile("./output/part9.tga", header, TopLayer);
	header.clear();
	TopLayer.clear();
	returnVector.clear();
	returnVector1.clear();
	returnVector2.clear();
	header1.clear();
	header2.clear();

	//cout << "Part 9 is: ";
	//openfile("./output/part9.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part9.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//Reverse Order Functionality
	openfile("./input/text2.tga", header, TopLayer);
	reverse(TopLayer.begin(), TopLayer.end());
	reverse(header.begin(), header.end());
	shipfile("./output/part10.tga", header, TopLayer);
	header.clear();
	TopLayer.clear();

	//cout << "Part 10 is: ";
	//openfile("./output/part10.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_part10.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	//Extra Credit
	openfile("./input/car.tga", header, TopLayer);
	openfile("./input/circles.tga", header1, returnVector);
	openfile("./input/pattern1.tga", header2, returnVector1);
	openfile("./input/text.tga", header3, returnVector2);
	ExtraCredit(returnVector2, returnVector1, TopLayer, returnVector, BottomLayer, header);
	shipfile1("./output/extracredit.tga", header, BottomLayer);

	//cout << "Extra credit is: ";
	//openfile("./output/ExtraCredit.tga", testheader1, testbody1);
	//openfile("./examples/EXAMPLE_extracredit.tga", testheader2, testbody2);
	//testfiles(testbody1, testbody2);
	//testheader1.clear();
	//testheader2.clear();
	//testbody1.clear();
	//testbody2.clear();
	
	return 0;
}
void openfile(string path, vector<HeaderInfo>& header, vector<BodyInfo>& body)
{
	fstream binary(path, ios_base::in | ios_base::binary);
	if (!binary.is_open())
	{
		cout << "file is not open.";
	}
	if (binary.is_open())

	{
		char Length;
		binary.read((char*)& Length, sizeof(Length));
		//int Lengthi = (int)Length;
		//cout << Lengthi << endl;

		char Map;
		binary.read((char*)& Map, 1);
		//int Mapi = (int)Map;
		//cout << Mapi << endl;

		char Image;
		binary.read((char*)& Image, 1);
		//int Imagei = (int)Image;
		//cout << Imagei << endl;

		short MapOrigin;
		binary.read((char*)& MapOrigin, 2);
		//cout << MapOrigin << endl;

		short MapLength;
		binary.read((char*)& MapLength, 2);
		//cout << MapLength << endl;

		char MapDepth;
		binary.read((char*)& MapDepth, 1);
		//int MapDepthi = (int)MapDepth;
		//cout << MapDepthi << endl;

		short XO;
		binary.read((char*)& XO, 2);
		//cout << XO << endl;

		short YO;
		binary.read((char*)& YO, 2);
		//cout << YO << endl;

		short ImageWidth;
		binary.read((char*)& ImageWidth, 2);
		//cout << ImageWidth << endl;

		short ImageHeight;
		binary.read((char*)& ImageHeight, 2);
		//cout << ImageHeight << endl;

		char PixelDepth;
		binary.read((char*)& PixelDepth, 1);
		//int PixelDepthi = (int)PixelDepth;
		//cout << PixelDepthi << endl;

		char ImageDescriptor;
		binary.read((char*)& ImageDescriptor, 1);
		//int ImageDescriptori = (int)ImageDescriptor;
		//cout << ImageDescriptori << endl;


		HeaderInfo a(Length, Map, Image, MapOrigin, MapLength, MapDepth, XO, YO, ImageWidth, ImageHeight, PixelDepth, ImageDescriptor);
		header.push_back(a);

		binary.seekg(0, binary.end);
		int length = binary.tellg();
		binary.seekg(0, binary.beg);
		binary.seekg(18, ios_base::cur);
		int pixelcount = header[0].imageHeight * header[0].imageWidth;
		//cout << length;
		for (unsigned int i = 0; i < pixelcount; i++)
		{
			unsigned char ColorBlue;
			binary.read((char*)& ColorBlue, 1);
			//unsigned int ColorBluei = (unsigned int)ColorBlue;
			//cout << ColorBluei;
			
			unsigned char ColorGreen;
			binary.read((char*)& ColorGreen, 1);
			//unsigned int ColorGreeni = (unsigned int)ColorGreen;
			//cout << ColorGreeni;
		
			
			unsigned char ColorRed;
			binary.read((char*)& ColorRed, 1);
			//unsigned int ColorRedi = (unsigned int)ColorRed;
			//cout << ColorRedi;

			//TopLayer.clear();
			BodyInfo b(ColorBlue, ColorGreen, ColorRed);
		
			body.push_back(b);
			
		}
	}
}
void shipfile(string path, vector<HeaderInfo>& header, vector<BodyInfo>& body)
{
	HeaderInfo head;
	BodyInfo bod;
	fstream binary(path, ios_base::out | ios_base::binary);

	binary.write((char*)&header[0].idLength, 1);

	//binary.write((char*)& head.colorMapType, 1);
	//binary.write((char*)& head.imageType, 1);
	//binary.write((char*)& head.colorMapOrigin, 2);
	//binary.write((char*)& head.colorMapLength, 2);
	//binary.write((char*)& head.colorMapDepth, 1);
	//binary.write((char*)& head.xOrigin, 2);
	//binary.write((char*)& head.yOrigin, 2);
	//binary.write((char*)& head.imageWidth, 2);
	//binary.write((char*)& head.imageHeight, 2);
	//binary.write((char*)& head.pixelDepth, 1);
	//binary.write((char*)& head.imageDescriptor, 1);
	//unsigned char r = '0'+ &header[0].colorMapType;
	binary.write((char*)&header[0].colorMapType, sizeof(header[0].colorMapType));
	
	binary.write((char*)&header[0].imageType, sizeof(header[0].imageType));
	binary.write((char*)&header[0].colorMapOrigin, sizeof(header[0].colorMapOrigin));
	binary.write((char*)&header[0].colorMapLength, sizeof(header[0].colorMapLength));
	
	binary.write((char*)&header[0].colorMapDepth, sizeof(header[0].colorMapDepth));

	binary.write((char*)&header[0].xOrigin, sizeof(header[0].xOrigin));
	binary.write((char*)&header[0].yOrigin, sizeof(header[0].yOrigin));
	binary.write((char*)&header[0].imageWidth, sizeof(header[0].imageWidth));
	binary.write((char*)&header[0].imageHeight, sizeof(header[0].imageHeight));
	
	binary.write((char*)&header[0].pixelDepth, sizeof(header[0].pixelDepth));
	
	binary.write((char*)&header[0].imageDescriptor, sizeof(header[0].imageDescriptor));
	//unsigned int ih = header[0].GetImageHeight();
	//cout << ih << endl;
	//unsigned int iw = header[0].GetImageWidth;
	//cout << iw << endl;
	//unsigned int count = ih * iw;
	//cout << count;
	for (unsigned int i = 0; i < body.size(); i++)
	{
		binary.write((char*)& body[i].blue, sizeof(body[i].blue));
		
		binary.write((char*)& body[i].green, sizeof(body[i].green));
		
		binary.write((char*)& body[i].red, sizeof(body[i].red));
		
	}
}
void Multiply(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header)
{
	unsigned char temp;
	unsigned char temp1;
	unsigned char temp2;
	unsigned char Atemp;
	unsigned char Atemp1;
	unsigned char Atemp2;
	int pixelcount = header[0].imageHeight * header[0].imageWidth;
	for (unsigned int i = 0; i < pixelcount; i++)
	{
		
		temp = BottomLayer[i].GetBlue();
		float tempi = (float)temp;
		
		
		temp1 = BottomLayer[i].GetGreen();
		float temp1i = (float)temp1;

		
		temp2 = BottomLayer[i].GetRed();
		float temp2i = (float)temp2;

		
		Atemp = TopLayer[i].GetBlue();
		float Atempi = (float)Atemp;

		
		Atemp1 = TopLayer[i].GetGreen();
		float Atemp1i = (float)Atemp1;

		
		Atemp2 = TopLayer[i].GetRed();
		float Atemp2i = (float)Atemp2;
		
		long Bluem = tempi * Atempi/255 + 0.5f;
		long Greenm = temp1i * Atemp1i/255 + 0.5f;
		long Redm = temp2i *Atemp2i/255 + 0.5f;

		unsigned char cBluem = (unsigned char)Bluem;
		unsigned char cGreenm = (unsigned char)Greenm;
		unsigned char cRedm = (unsigned char)Redm;

		BodyInfo b(cBluem, cGreenm, cRedm);
		returnVector.push_back(b);
	}
}
void Subtract(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header)
{
	unsigned char temp;
	unsigned char temp1;
	unsigned char temp2;
	unsigned char Atemp;
	unsigned char Atemp1;
	unsigned char Atemp2;
	int pixelcount = header[0].imageHeight * header[0].imageWidth;
	for (unsigned int i = 0; i < pixelcount; i++)
	{
		temp = BottomLayer[i].GetBlue();
		int tempi = (int)temp;
		
		temp1 = BottomLayer[i].GetGreen();
		int temp1i = (int)temp1;
		
		temp2 = BottomLayer[i].GetRed();
		int temp2i = (int)temp2;
		
		Atemp = TopLayer[i].GetBlue();
		int Atempi = (int)Atemp;
		
		Atemp1 = TopLayer[i].GetGreen();
		int Atemp1i = (int)Atemp1;
		
		Atemp2 = TopLayer[i].GetRed();
		int Atemp2i = (int)Atemp2;

		long Bluem = tempi - Atempi;
		long Greenm = temp1i - Atemp1i;
		long Redm = temp2i - Atemp2i;

		if (Bluem > 255)
		{
			Bluem = 255;
		}
		if (Greenm > 255)
		{
			Greenm = 255;
		}
		if (Redm > 255)
		{
			Redm = 255;
		}
		if (Bluem < 0)
		{
			Bluem = 0;
		}
		if (Greenm < 0)
		{
			Greenm = 0;
		}
		if (Redm < 0)
		{
			Redm = 0;
		}

		unsigned char cBluem = (unsigned char)Bluem;
		unsigned char cGreenm = (unsigned char)Greenm;
		unsigned char cRedm = (unsigned char)Redm;



		BodyInfo b(cBluem, cGreenm, cRedm);
		returnVector.push_back(b);
	}
}
void Screen(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header) 
{

	{
		unsigned char temp;
		unsigned char temp1;
		unsigned char temp2;
		unsigned char Atemp;
		unsigned char Atemp1;
		unsigned char Atemp2;
		int pixelcount = header[0].imageHeight * header[0].imageWidth;
		for (unsigned int i = 0; i < pixelcount; i++)
		{
			temp = BottomLayer[i].GetBlue();
			float tempi = (float)temp;

			temp1 = BottomLayer[i].GetGreen();
			float temp1i = (float)temp1;

			temp2 = BottomLayer[i].GetRed();
			float temp2i = (float)temp2;

			Atemp = TopLayer[i].GetBlue();
			float Atempi = (float)Atemp;

			Atemp1 = TopLayer[i].GetGreen();
			float Atemp1i = (float)Atemp1;

			Atemp2 = TopLayer[i].GetRed();
			float Atemp2i = (float)Atemp2;

			float x, y, z, xx, yy, zz, xxx, yyy, zzz;
			x = 255 - tempi;
			xx = 255 - Atempi;
			y = 255 - temp1i;
			yy = 255 - Atemp1i;
			z = 255 - temp2i;
			zz= 255 - Atemp2i;
			xxx = 255 - ((x) * (xx))/255 + 0.5f;
			yyy = 255 - ((y) * (yy))/255 + 0.5f;
			zzz = 255 - ((z) * (zz))/255 + 0.5f;
			//cout << "This is x " << tempi << " This is 255 - x" << x << endl;
			if (xxx < 0)
			{
				xxx = 0;
			}
			if (yyy < 0)
			{
				yyy = 0;
			}
			if (zzz < 0)
			{
				zzz = 0;
			}
			if (xxx > 255)
			{
				xxx = 255;
			}
			if (yyy > 255)
			{
				yyy = 255;
			}
			if (zzz > 255)
			{
				zzz = 255;
			}
			

			long Bluem = xxx;
			long Greenm = yyy;
			long Redm = zzz;


			unsigned char cBluem = (unsigned char)Bluem;
			unsigned char cGreenm = (unsigned char)Greenm;
			unsigned char cRedm = (unsigned char)Redm;



			BodyInfo b(cBluem, cGreenm, cRedm);
			returnVector.push_back(b);
		}
	}
}
void Overlay(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header)
{
	unsigned char temp;
	unsigned char temp1;
	unsigned char temp2;
	unsigned char Atemp;
	unsigned char Atemp1;
	unsigned char Atemp2;
	int pixelcount = header[0].imageHeight * header[0].imageWidth;
	for (unsigned int i = 0; i < pixelcount; i++)
	{
		temp = BottomLayer[i].GetBlue();
		float tempi = (float)temp;

		temp1 = BottomLayer[i].GetGreen();
		float temp1i = (float)temp1;

		temp2 = BottomLayer[i].GetRed();
		float temp2i = (float)temp2;

		Atemp = TopLayer[i].GetBlue();
		float Atempi = (float)Atemp;

		Atemp1 = TopLayer[i].GetGreen();
		float Atemp1i = (float)Atemp1;

		Atemp2 = TopLayer[i].GetRed();
		float Atemp2i = (float)Atemp2;

		float x, y, z, xx, yy, zz, xxx, yyy, zzz;
		x = tempi/255;
		xx = Atempi / 255;
		y = temp1i / 255;
		yy = Atemp1i / 255;
		z = temp2i / 255;
		zz = Atemp2i / 255;

		if (x < 0.5) //blue bottom layer
		{
			xxx = 2* (x * xx);
		}
		else
		{
			xxx = 1 - 2*(1 - xx) * (1 - x);
		}
		if (y < 0.5) //Green bottom layer
		{
			yyy = 2 *(y * yy);
		}
		else
		{
			yyy = 1 - 2*(1 - yy) * (1 - y);
		}
		if (z < 0.5) // Red bottom layer
		{
			zzz = 2 *(z * zz);
		}
		else
		{
			zzz = 1 - 2*(1 - zz) * (1 - z);
		}
		


		long Bluem = (xxx*255)+0.5f;
		long Greenm = (yyy * 255) + 0.5f;
		long Redm = (zzz * 255) + 0.5f;


		unsigned char cBluem = (unsigned char)Bluem;
		unsigned char cGreenm = (unsigned char)Greenm;
		unsigned char cRedm = (unsigned char)Redm;



		BodyInfo b(cBluem, cGreenm, cRedm);
		returnVector.push_back(b);
	}
}
void Green200(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header)
{

	{
		
		unsigned char Atemp;
		unsigned char Atemp1;
		unsigned char Atemp2;
		int pixelcount = header[0].imageHeight * header[0].imageWidth;
		for (unsigned int i = 0; i < pixelcount; i++)
		{

			Atemp = TopLayer[i].GetBlue();
			int Atempi = (int)Atemp;


			Atemp1 = TopLayer[i].GetGreen();
			int Atemp1i = (int)Atemp1;


			Atemp2 = TopLayer[i].GetRed();
			int Atemp2i = (int)Atemp2;

			long Bluem = Atempi;

			long Greenm = Atemp1i + 200;
			if (Greenm > 255)
			{
				Greenm = 255;
			}
			long Redm = Atemp2i;


			unsigned char cBluem = (unsigned char)Bluem;
			unsigned char cGreenm = (unsigned char)Greenm;
			unsigned char cRedm = (unsigned char)Redm;

			BodyInfo b(cBluem, cGreenm, cRedm);
			returnVector.push_back(b);
		}
	}
}
void Red4Blue0(vector<BodyInfo>& returnVector, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header)
{

	{

		unsigned char Atemp;
		unsigned char Atemp1;
		unsigned char Atemp2;
		int pixelcount = header[0].imageHeight * header[0].imageWidth;
		for (unsigned int i = 0; i < pixelcount; i++)
		{

			Atemp = TopLayer[i].GetBlue();
			int Atempi = (int)Atemp;


			Atemp1 = TopLayer[i].GetGreen();
			int Atemp1i = (int)Atemp1;


			Atemp2 = TopLayer[i].GetRed();
			int Atemp2i = (int)Atemp2;

			long Bluem = (0 * Atempi);
			long Greenm = Atemp1i;
			long Redm = (4 * Atemp2i);
			if (Redm > 255)
			{
				Redm = 255;
			}

			unsigned char cBluem = (unsigned char)Bluem;
			unsigned char cGreenm = (unsigned char)Greenm;
			unsigned char cRedm = (unsigned char)Redm;

			BodyInfo b(cBluem, cGreenm, cRedm);
			returnVector.push_back(b);
		}
	}
}
void SeparateChannels(vector<BodyInfo>& returnVector, vector<BodyInfo>& returnVector1, vector<BodyInfo>& returnVector2, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header)
{
	{

		unsigned char Atemp;
		unsigned char Atemp1;
		unsigned char Atemp2;
		int pixelcount = header[0].imageHeight * header[0].imageWidth;
		for (unsigned int i = 0; i < pixelcount; i++)
		{

			Atemp = TopLayer[i].GetBlue();
			int Atempi = (int)Atemp;


			Atemp1 = TopLayer[i].GetGreen();
			int Atemp1i = (int)Atemp1;


			Atemp2 = TopLayer[i].GetRed();
			int Atemp2i = (int)Atemp2;

			long Bluem = Atempi;

			long Greenm = Atemp1i;

			long Redm = Atemp2i;


			unsigned char cBluem = (unsigned char)Bluem;
			unsigned char cGreenm = (unsigned char)Greenm;
			unsigned char cRedm = (unsigned char)Redm;
			unsigned char temp = '0';

			BodyInfo b(cBluem, cBluem, cBluem);
			returnVector.push_back(b);
			BodyInfo c(cGreenm, cGreenm, cGreenm);
			returnVector1.push_back(c);
			BodyInfo d(cRedm, cRedm, cRedm);
			returnVector2.push_back(d);
		}
	}
}
void CombineChannels(vector<BodyInfo>& returnVector, vector<BodyInfo>& returnVector1, vector<BodyInfo>& returnVector2, vector<BodyInfo>& TopLayer, vector<HeaderInfo>& header)
{

	{
		{

			unsigned char Atemp;
			unsigned char Atemp1;
			unsigned char Atemp2;
			int pixelcount = header[0].imageHeight * header[0].imageWidth;
			for (unsigned int i = 0; i < pixelcount; i++)
			{

				Atemp = returnVector2[i].GetBlue();
				int Atempi = (int)Atemp;


				Atemp1 = returnVector1[i].GetGreen();
				int Atemp1i = (int)Atemp1;


				Atemp2 = returnVector[i].GetRed();
				int Atemp2i = (int)Atemp2;

				long Bluem = Atempi;

				long Greenm = Atemp1i;

				long Redm = Atemp2i;


				unsigned char cBluem = (unsigned char)Bluem;
				unsigned char cGreenm = (unsigned char)Greenm;
				unsigned char cRedm = (unsigned char)Redm;
				unsigned char temp = '0';

				BodyInfo b(cBluem, cGreenm, cRedm);
				TopLayer.push_back(b);
	
			}
		}
	}
}
void ExtraCredit(vector<BodyInfo>& text, vector<BodyInfo>& swirls, vector<BodyInfo>& car, vector<BodyInfo>& circles, vector<BodyInfo>& BottomLayer, vector<HeaderInfo>& header)
{

	unsigned char Atemp;
	unsigned char Atemp1;
	unsigned char Atemp2;
	int pixelcount = 2* header[0].imageHeight * header[0].imageWidth;
	int widthcount = 2 * header[0].imageWidth;
	int heightcount = 2 * header[0].imageHeight;
	int individualCount = header[0].imageHeight * header[0].imageWidth;
	int e = 0;
	int f = 0;
	int g = 0;
	int h = 0;
	for (unsigned int i = 0; i < 1024; i++) //height
	{
		if(i < 512)
		{
			for (unsigned int j = 0; j < 1024; j++) // nested for loops are for width
			{
				if (j < 512)
				{

					Atemp = text[e].GetBlue();
					int Atempi = (int)Atemp;


					Atemp1 = text[e].GetGreen();
					int Atemp1i = (int)Atemp1;


					Atemp2 = text[e].GetRed();
					int Atemp2i = (int)Atemp2;

					long Bluem = Atempi;

					long Greenm = Atemp1i;

					long Redm = Atemp2i;
					e++;

					unsigned char cBluem = (unsigned char)Bluem;
					unsigned char cGreenm = (unsigned char)Greenm;
					unsigned char cRedm = (unsigned char)Redm;
					unsigned char temp = '0';
					BodyInfo b(cBluem, cGreenm, cRedm);
					BottomLayer.push_back(b);
				}
				else 
				{
					Atemp = swirls[f].GetBlue();
					int Atempi = (int)Atemp;


					Atemp1 = swirls[f].GetGreen();
					int Atemp1i = (int)Atemp1;


					Atemp2 = swirls[f].GetRed();
					int Atemp2i = (int)Atemp2;

					long Bluem = Atempi;

					long Greenm = Atemp1i;

					long Redm = Atemp2i;
					f++;

					unsigned char cBluem = (unsigned char)Bluem;
					unsigned char cGreenm = (unsigned char)Greenm;
					unsigned char cRedm = (unsigned char)Redm;
					unsigned char temp = '0';
					BodyInfo b(cBluem, cGreenm, cRedm);
					BottomLayer.push_back(b);
				}
			}

		}

		else 
		{
			for (unsigned int j = 0; j < 1024; j++)
			{
				if (j < 512)
				{

					Atemp = car[g].GetBlue();
					int Atempi = (int)Atemp;


					Atemp1 = car[g].GetGreen();
					int Atemp1i = (int)Atemp1;


					Atemp2 = car[g].GetRed();
					int Atemp2i = (int)Atemp2;

					long Bluem = Atempi;

					long Greenm = Atemp1i;

					long Redm = Atemp2i;
					g++;

					unsigned char cBluem = (unsigned char)Bluem;
					unsigned char cGreenm = (unsigned char)Greenm;
					unsigned char cRedm = (unsigned char)Redm;
					unsigned char temp = '0';
					BodyInfo b(cBluem, cGreenm, cRedm);
					BottomLayer.push_back(b);
				}
				else 
				{
					Atemp = circles[h].GetBlue();
					int Atempi = (int)Atemp;


					Atemp1 = circles[h].GetGreen();
					int Atemp1i = (int)Atemp1;


					Atemp2 = circles[h].GetRed();
					int Atemp2i = (int)Atemp2;

					long Bluem = Atempi;

					long Greenm = Atemp1i;

					long Redm = Atemp2i;
					h++;

					unsigned char cBluem = (unsigned char)Bluem;
					unsigned char cGreenm = (unsigned char)Greenm;
					unsigned char cRedm = (unsigned char)Redm;
					unsigned char temp = '0';
					BodyInfo b(cBluem, cGreenm, cRedm);
					BottomLayer.push_back(b);
				}
			}

		}

	}
			
}
void shipfile1(string path, vector<HeaderInfo>& header, vector<BodyInfo>& body)
{

	fstream binary(path, ios_base::out | ios_base::binary);

	binary.write((char*)& header[0].idLength, 1);

	short Atemp = header[0].imageWidth*2;
	//int Atempi = (int)Atemp;
	//cout << Atempi << endl;
	//Atempi = Atempi * 2;
	//cout << Atemp;
	short Atemp1 = header[0].imageHeight*2;
	/*int Atemp1i = (int)Atemp1;
	Atemp1i = Atemp1i * 2;*/

	//char width = '1024';
	//char height = '1024';

	

	binary.write((char*)& header[0].colorMapType, sizeof(header[0].colorMapType));

	binary.write((char*)& header[0].imageType, sizeof(header[0].imageType));
	binary.write((char*)& header[0].colorMapOrigin, sizeof(header[0].colorMapOrigin));
	binary.write((char*)& header[0].colorMapLength, sizeof(header[0].colorMapLength));

	binary.write((char*)& header[0].colorMapDepth, sizeof(header[0].colorMapDepth));

	binary.write((char*)& header[0].xOrigin, sizeof(header[0].xOrigin));
	binary.write((char*)& header[0].yOrigin, sizeof(header[0].yOrigin));
	binary.write((char*)& Atemp, 2);
	binary.write((char*)& Atemp1, 2);

	binary.write((char*)& header[0].pixelDepth, sizeof(header[0].pixelDepth));

	binary.write((char*)& header[0].imageDescriptor, sizeof(header[0].imageDescriptor));
	//unsigned int ih = header[0].GetImageHeight();
	//cout << ih << endl;
	//unsigned int iw = header[0].GetImageWidth;
	//cout << iw << endl;
	//unsigned int count = ih * iw;
	//cout << count;
	for (unsigned int i = 0; i < body.size(); i++)
	{
		binary.write((char*)& body[i].blue, sizeof(body[i].blue));

		binary.write((char*)& body[i].green, sizeof(body[i].green));

		binary.write((char*)& body[i].red, sizeof(body[i].red));

	}
}
//void testfiles(vector<BodyInfo>& bottomLayer, vector<BodyInfo>& TopLayer)
//{
//	unsigned char temp;
//	unsigned char temp1;
//	unsigned char temp2;
//	unsigned char Atemp;
//	unsigned char Atemp1;
//	unsigned char Atemp2;
//	string x = "true";
//
//	for (unsigned int i = 0; i < size(bottomLayer); i++)
//	{
//		temp = bottomLayer[i].GetBlue();
//		int tempi = (int)temp;
//
//		temp1 = bottomLayer[i].GetGreen();
//		int temp1i = (int)temp1;
//
//		temp2 = bottomLayer[i].GetRed();
//		int temp2i = (int)temp2;
//
//		Atemp = TopLayer[i].GetBlue();
//		int Atempi = (int)Atemp;
//
//		Atemp1 = TopLayer[i].GetGreen();
//		int Atemp1i = (int)Atemp1;
//
//		Atemp2 = TopLayer[i].GetRed();
//		int Atemp2i = (int)Atemp2;
//
//		if (temp != Atemp || temp1 != Atemp1 || temp2 != Atemp2)
//		{
//			x = "false";
//			cout << tempi << " blue " << Atempi << endl;
//			cout << temp1i << " Green " << Atemp1i << endl;
//			cout << temp2i << " red " << Atemp2i << endl;
//		}
//
//		//if (tempi != Atemp1)
//		//{
//		//	x = "false";
//		//	cout << tempi << " and " << Atemp1 << " end ";
//		//}
//		//if (temp1i != Atemp1i)
//		//{
//		//	x = "false";
//		//}
//		//if (temp2i != Atemp2i)
//		//{
//		//	x = "false";
//		//}
//
//	}
//	cout << x << endl;
//}