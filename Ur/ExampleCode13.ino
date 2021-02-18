if (T < 3){
    if (timeMin >= 100){
      lcd.setCursor (5,0);
    }

    if (timeMin < 100 && timeMin >= 10){
      lcd.setCursor (5,0);
      lcd.print(" ");
      lcd.setCursor (6,0);
    }

    if (timeMin < 10){
      lcd.setCursor (6,0);
      lcd.print(" ");
      lcd.setCursor (7,0);
    }

    lcd.print(timeMin);
    lcd.setCursor (8,0);
    lcd.print(":");

    if ((timeSek - 60 * timeMin) >= 10){
      lcd.setCursor (9,0);
    }

    if ((timeSek - 60 * timeMin) < 10){
      lcd.setCursor (9,0);
      lcd.print(0);
      lcd.setCursor (10,0);
    }
    lcd.print(timeSek - 60 * timeMin);
  }
