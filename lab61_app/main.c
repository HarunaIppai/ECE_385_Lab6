
/*int main()
{
	int i = 0;
	volatile unsigned int *LED_PIO = (unsigned int*)0x70; //make a pointer to access the PIO block

	*LED_PIO = 0; //clear all LEDs
	while ( (1+1) != 3) //infinite loop
	{
		for (i = 0; i < 100000; i++); //software delay
		*LED_PIO |= 0x1; //set LSB
		for (i = 0; i < 100000; i++); //software delay
		*LED_PIO &= ~0x1; //clear LSB
	}
	return 1; //never gets here
}*/

int main() {

	volatile unsigned int *LED_PIO = (unsigned int*)0x70;
	volatile unsigned int *SW_PIO = (unsigned int*)0x60;
	volatile unsigned int *BTN_PIO = (unsigned int*)0x50;

	*LED_PIO = 0;
	while(1) {
		if(*BTN_PIO == 0){
			*LED_PIO += *SW_PIO;
			*LED_PIO = *LED_PIO > 255 ? *LED_PIO % 255 : *LED_PIO;
			for (int i = 0; i < 100000; i++); //software delay
		}
	}
	return 1;

}
