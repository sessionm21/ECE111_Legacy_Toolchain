#include "mbed.h"


/*  ------ sample usage------

    #include "mbed.h"
    #include "SLCD.h"
    
    SLCD slcd;
    
    main()
    {
        slcd.printf("1234");    // standard printf function, only charaters in ASCII_TO_WF_CODIFICATION_TABLE will display
        slcd.putc("A");         // prints a single character 
        slcd.Write_Char('A');   // prints a single character
        slcd.All_Segments(y);   // y=1 for ALL segments on, 0 for ALL segments off  
        slcd.DPx(y);            // x=DP1 to DP3, y=1 for on 0 for off
        slcd.Colon(y);          // y=1 for on, 0 for off
        slcd.CharPosition=x;    // x=0 to 3, 0 is start position
        slcd.Home();            // sets next charater to posistion 0 (start)
        slcd.Contrast (x);      // set contrast x=0 - 15, 0 lightest, 15 darkest    
    }   
*/

class SLCD : public Stream {
    public:
    SLCD();
    
    void init();
    void Write_Char(char lbValue);
    void Home (void);
    void Contrast (uint8_t lbContrast);
    void All_Segments (int);     
    void DP1 (int);
    void DP2 (int);
    void DP3 (int);
    void Colon (int);     
    uint8_t CharPosition;
         
    virtual int _putc(int c);
    virtual int _getc() {
        return 0;
    }  
};
