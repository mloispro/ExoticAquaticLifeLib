
echo Upload File: %1.hex
echo Platform: %2
echo COM: %3
IF /I "%2"=="ATmega328P" (
	echo Uploading to Uno...
	start "" /wait /b "C:\Program Files (x86)\Arduino\hardware\tools\avr\bin\avrdude" -C"C:\Program Files (x86)\Arduino\hardware\tools\avr/etc/avrdude.conf" -v -p%2 -carduino -P%3 -b115200 -D -Uflash:w:"%1.hex":i
) ELSE (
    echo **This Script Doesnt Support Platform: %2 **
)
rem pause