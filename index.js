const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const {PORT}= require('./severconfig')
app.use(bodyParser.json());

app.listen(PORT,()=>{
    console.log(`Server is running on port ${PORT}.`);
});