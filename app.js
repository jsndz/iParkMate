const SerialPort = require("serialport");
const Readline = require("@serialport/parser-readline");

const PORT = new serialPort("COM3", { baudRate: 9600 });

const parser = new Readline();
PORT.pipe(parser);

parser.on("data", (line) => {
  console.log(line);
});

PORT.write("ROBOT POWER ON\n");
