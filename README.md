# Parallel Port Controller

This is a simple C++ program to control a parallel port on a Linux system. It allows you to turn on and off the data pins of the parallel port.

## Compilation

To compile the program, use the following command:

```bash
g++ para.cpp -o para
```

## Running

To run the program, use the following command:

```bash
./para
```

The program will then wait for your input. Each time you press a key and then enter, the program will toggle the data pins on the parallel port. To quit the program, press 'q' and then enter.

## Permissions

To be able to access the parallel port, your user needs to be a member of the `lp` group. You can add your user to the `lp` group with the following command:

```bash
sudo usermod -a -G lp $USER
```

You will need to log out and log back in for this change to take effect.

### Youtube video
I have created the following [Youtube short](https://youtube.com/shorts/hfSnNnBhJtc) showing how this software works for controlling the parallel port

