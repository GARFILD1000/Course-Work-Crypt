void RestoreOptions();

//   процедура заполняет структуры с натройками изначальными значениями
void RestoreOptions(){
    point_color.blue=200;
    point_color.green=50;
    point_color.red=50;
    
    punkt_color.blue=200;
    punkt_color.green=200;
    punkt_color.red=200;
    
    word_color.blue=200;
    word_color.green=200;
    word_color.red=200;
    
    negative_color.blue=20;
    negative_color.green=20;
    negative_color.red=250;
    
    bg_color.red=0;
    bg_color.blue=0;
    bg_color.green=0;
    
    options.input_file_name="InputFile.txt";
    options.output_file_name="OutputFile.txt";
    options.file_directory="..\\files\\";
}
