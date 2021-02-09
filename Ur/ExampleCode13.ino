void loop(exception){
  for (int i = 0; i < size(buttList); i++) {
    if (i != exception){
      buttList[i] = LOW;
    }
    else{
      buttList[i] = HIGH;
