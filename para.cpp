#include <iostream>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/parport.h>
#include <linux/ppdev.h>
#include <unistd.h>

int main() {
	const char* device = "/dev/parport0";
	int fd = open(device, O_RDWR);

	if (fd == -1) {
		std::cerr << "Error: Could not open " << device << std::endl;
		std::cerr << "Make sure your user is in the 'lp' group: sudo usermod -a -G lp $USER" << std::endl;
		return 1;
	}

	// Claim the port
	if (ioctl(fd, PPCLAIM) == -1) {
		std::cerr << "Error: Could not claim parallel port" << std::endl;
		close(fd);
		return 1;
	}

	char input = '\0';
	bool on = true;

	unsigned char data = 0;
	while(input != 'q')
	{
		data = on ? 255 : 0;
		on = !on;
		std::cout << "Input: ";
		std::cin >> input;
		// Write 255 (0xFF) to turn on all data pins
		if (ioctl(fd, PPWDATA, &data) == -1) {
			std::cerr << "Error: Could not write to parallel port" << std::endl;
			ioctl(fd, PPRELEASE);
			close(fd);
			return 1;
		}

		std::cout << "Successfully wrote "<< int(data)<< " to parallel port data pins" << std::endl;
	}
	// Release the port
	ioctl(fd, PPRELEASE);
	close(fd);

	std::cout << "Program has exited successfully" << std::endl;
	return 0;
}

