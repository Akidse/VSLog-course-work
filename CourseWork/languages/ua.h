std::string get_message(text msg)
{
	std::string message;
	switch(msg)
	{
	case LOGIN_SUCCESS:
		message = "Вхiд виконано успiшно";
		break;
	case LOGIN_FAIL:
		message = "Ви ввели невiрнi данi для авторизацiї";
		break;
	case START_PAGE:
		message = "  Вхiд виконано успiшно\n  Ласкаво просимо до VSLOG v.1.0.\n\n  ¶¶``¶¶```¶¶¶¶```¶¶```````¶¶¶¶````¶¶¶¶\n  ¶¶``¶¶``¶¶``````¶¶``````¶¶``¶¶``¶¶\n  ¶¶``¶¶```¶¶¶¶```¶¶``````¶¶``¶¶``¶¶`¶¶¶\n  `¶¶¶¶```````¶¶``¶¶``````¶¶``¶¶``¶¶``¶¶\n  ``¶¶`````¶¶¶¶```¶¶¶¶¶¶```¶¶¶¶````¶¶¶¶\n\n   Це найзручнiший журнал вiдвiдування у свiтi! Введiть -help для списку команд";
		break;
	case HELP:
		message = "Це список команд для використання VSLog:\r\n -help -- допомога \r\n -clear -- очистити вiкно програми \r\n -adduser -- додати нового користувача \r\n -pass -- змiнити свiй пароль \r\n -users -- отримати список користувачiв \r\n -userdel -- видалити користувача \r\n -today -- вивести поточну дату \r\n -groupslist -- вивести список груп\r\n- addgroup -- додати нову групу\r\n -setgroup -- встановити групу як поточну\r\n -studentslist -- вивести список студентiв\r\n -addstudent -- додати студента в поточну групу\r\n -writedown -- записати нову замiтку в журнал\r\n -display -- вивести журнал поточної групи";
		break;
	case WRONG_COMMAND:
		message = "Ви ввели невiрну команду. Напишiть -help щоб вивести список команд.";
		break;
	case ADD_USER_SUCCESS:
		message = "Користувач був добавлений успiшно";
		break;
	case ADD_USER_FAIL:
		message = "Помилка при створеннi користувача";
		break;
	case ADD_USER_ERR_PASS:
		message = "Паролi не збiгаються";
		break;
	case ADD_USER_EXISTED:
		message = "Такий користувач уже iснує";
		break;
	case CHANGE_PASS_SUCCESS:
		message = "Пароль змiнений успiшно";
		break;
	case USER_NOT_EXIST:
		message = "Такий користувач не iснує";
		break;	
	case USER_CANT_DELETE_HIMSELF:
		message = "Ви не можете видалити свiй облiковий запис";
		break;
	case USER_DELETE_SUCCESS:
		message = "Користувач був видалений успiшно";
		break;	
	case USER_DELETE_FAIL:
		message = "Помилка при видаленнi користувача";
		break;
	case NOT_ALLOWED:
		message = "У вас нема прав на виконання цiєї команди";
		break;
	case GROUP_NOT_FOUND:
		message = "Така група не iснує";
		break;
	case GROUP_CANT_CREATE:
		message = "Не можу створити групу з таким iменем";
		break;
	case GROUP_CREATED_SUCCESS:
		message = "Група створена успiшно";
		break;
	case GROUP_NOT_CHOSEN:
		message = "Група не була вибрана. Будь ласка, виберiть групу";
		break;
	case STUDENTS_FILE_NOT_FOUND:
		message = "Не можу найти список студентiв";
		break;
	case BAD_YEAR:
		message = "Ви ввели невiрний рiк";
		break;
	case BAD_MONTH:
		message = "Ви ввели невiрний мiсяць";
		break;
	case STUDENT_NOT_FOUND:
		message = "Студент не знайдений";
		break;
	case BAD_DATE:
		message = "Ви ввели невiрну дату";
		break;
	case BAD_MARK:
		message = "Ви ввели невiрну оцiнку";
		break;
	case ENTER_NAME:
		message = "Введiть iм'я користувача: ";
		break;
	case ENTER_PASSWORD:
		message = "Введiть пароль: ";
		break;
	case ENTER_PASSWORD_AGAIN:
		message = "Введiть пароль ще раз: ";
		break;
	case ENTER_GROUP_NAME:
		message = "Введiть назву групи:";
		break;
	case ENTER_STUDENT_NAME:
		message = "Введiть iм'я студента: ";
		break;
	case STUDENTS_EMPTY:
		message = "Студентiв не знайдено";
		break;
	case JOURNAL_NAMES:
		message = "Студенти";
		break;
	case ENTER_YEAR:
		message = "Введiть рiк: ";
		break;
	case ENTER_MONTH:
		message = "Введiть мiсяць:  ";
		break;
	case WRITE_DOWN:
		message = "Щоб додати новий запис, введiть такi данi: ";
		break;
	case ENTER_DATE:
		message = "Введiть дату в такому форматi рiк.мiсяць.день: ";
		break;
	case ENTER_MARK:
		message = "Введiть оцiнку(1-5), або 0, якщо студент не був присутнiй: ";
		break;
	}

	return message;
}