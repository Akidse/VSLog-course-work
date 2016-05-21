std::string get_message(text msg)
{
	std::string message;
	switch(msg)
	{
	case LOGIN_SUCCESS:
		message = "Login successfull";
		break;
	case LOGIN_FAIL:
		message = "You enter bad login data";
		break;
	case START_PAGE:
		message = "  Login successfull\n  Welcome to VSLOG v.1.0.\n\n  ¶¶``¶¶```¶¶¶¶```¶¶```````¶¶¶¶````¶¶¶¶\n  ¶¶``¶¶``¶¶``````¶¶``````¶¶``¶¶``¶¶\n  ¶¶``¶¶```¶¶¶¶```¶¶``````¶¶``¶¶``¶¶`¶¶¶\n  `¶¶¶¶```````¶¶``¶¶``````¶¶``¶¶``¶¶``¶¶\n  ``¶¶`````¶¶¶¶```¶¶¶¶¶¶```¶¶¶¶````¶¶¶¶\n\n   It is the most easier visiting college log! Tap -help for more information";
		break;
	case HELP:
		message = "This is help manual for using VSLog:\r\n -help -- help manual \r\n -clear -- clear window \r\n -adduser -- add new user \r\n -pass -- change your pass \r\n -users -- get list of users \r\n -userdel -- delete user \r\n -today -- display today's date \r\n -groupslist -- display groups list \r\n -groupslist -- display groups list\r\n- addgroup -- add new group\r\n -setgroup -- set group as currrent\r\n -studentslist -- display list of students\r\n -addstudent -- add student to current group\r\n -writedown -- add new notice into journal\r\n -display -- display journal with current group";
		break;
	case WRONG_COMMAND:
		message = "You wrote wrong command. Tap -help for information about commands.";
		break;
	case ADD_USER_SUCCESS:
		message = "User added successfully";
		break;
	case ADD_USER_FAIL:
		message = "Can't create user file.";
		break;
	case ADD_USER_ERR_PASS:
		message = "Passwords are not the same.";
		break;
	case ADD_USER_EXISTED:
		message = "This user already exists";
		break;
	case CHANGE_PASS_SUCCESS:
		message = "Pass changed successfully";
		break;
	case USER_NOT_EXIST:
		message = "Such user do not exist";
		break;	
	case USER_CANT_DELETE_HIMSELF:
		message = "You can't delete your user data by yourself";
		break;
	case USER_DELETE_SUCCESS:
		message = "User was deleted successfull";
		break;	
	case USER_DELETE_FAIL:
		message = "Can't delete user";
		break;
	case NOT_ALLOWED:
		message = "You are not allowed to do this thing";
		break;
	case GROUP_NOT_FOUND:
		message = "Such group do not exists";
		break;
	case GROUP_CANT_CREATE:
		message = "Can't create group with such name";
		break;
	case GROUP_CREATED_SUCCESS:
		message = "Group created successfully";
		break;
	case GROUP_NOT_CHOSEN:
		message = "Group wasn't chosen. Please choose group";
		break;
	case STUDENTS_FILE_NOT_FOUND:
		message = "Can't find students list";
		break;
	case BAD_YEAR:
		message = "You enter wrong year";
		break;
	case BAD_MONTH:
		message = "You enter wrong month";
		break;
	case STUDENT_NOT_FOUND:
		message = "Student not found";
		break;
	case BAD_DATE:
		message = "You enter bad date";
		break;
	case BAD_MARK:
		message = "You enter bad mark";
		break;
	case ENTER_NAME:
		message = "Enter username: ";
		break;
	case ENTER_PASSWORD:
		message = "Enter password: ";
		break;
	case ENTER_PASSWORD_AGAIN:
		message = "Enter password again: ";
		break;
	case ENTER_GROUP_NAME:
		message = "Enter group name:";
		break;
	case ENTER_STUDENT_NAME:
		message = "Enter student name: ";
		break;
	case STUDENTS_EMPTY:
		message = "Without students";
		break;
	case JOURNAL_NAMES:
		message = "Names";
		break;
	case ENTER_YEAR:
		message = "Write year: ";
		break;
	case ENTER_MONTH:
		message = "Write month:  ";
		break;
	case WRITE_DOWN:
		message = "To write-down something enter such data: ";
		break;
	case ENTER_DATE:
		message = "Write date in format: year.month.day: ";
		break;
	case ENTER_MARK:
		message = "Write mark(1-5), 0 if student wasn't on lesson: ";
		break;
	}

	return message;
}