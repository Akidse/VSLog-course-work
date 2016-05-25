std::string get_message(text msg)
{
	std::string message;
	switch(msg)
	{
	case LOGIN_SUCCESS:
		message = "��i� �������� ���i���";
		break;
	case LOGIN_FAIL:
		message = "�� ����� ���i��i ���i ��� ���������i�";
		break;
	case START_PAGE:
		message = "  ��i� �������� ���i���\n  ������� ������� �� VSLOG v.1.0.\n\n  ��``��```����```��```````����````����\n  ��``��``��``````��``````��``��``��\n  ��``��```����```��``````��``��``��`���\n  `����```````��``��``````��``��``��``��\n  ``��`````����```������```����````����\n\n   �� ��������i��� ������ �i��i������� � ��i�i! ����i�� -help ��� ������ ������";
		break;
	case HELP:
		message = "�� ������ ������ ��� ������������ VSLog:\r\n -help -- �������� \r\n -clear -- �������� �i��� �������� \r\n -adduser -- ������ ������ ����������� \r\n -pass -- ��i���� ��i� ������ \r\n -users -- �������� ������ ����������i� \r\n -userdel -- �������� ����������� \r\n -today -- ������� ������� ���� \r\n -groupslist -- ������� ������ ����\r\n- addgroup -- ������ ���� �����\r\n -setgroup -- ���������� ����� �� �������\r\n -studentslist -- ������� ������ �������i�\r\n -addstudent -- ������ �������� � ������� �����\r\n -writedown -- �������� ���� ���i��� � ������\r\n -display -- ������� ������ ������� �����";
		break;
	case WRONG_COMMAND:
		message = "�� ����� ���i��� �������. �����i�� -help ��� ������� ������ ������.";
		break;
	case ADD_USER_SUCCESS:
		message = "���������� ��� ���������� ���i���";
		break;
	case ADD_USER_FAIL:
		message = "������� ��� ��������i �����������";
		break;
	case ADD_USER_ERR_PASS:
		message = "�����i �� ��i�������";
		break;
	case ADD_USER_EXISTED:
		message = "����� ���������� ��� i���";
		break;
	case CHANGE_PASS_SUCCESS:
		message = "������ ��i����� ���i���";
		break;
	case USER_NOT_EXIST:
		message = "����� ���������� �� i���";
		break;	
	case USER_CANT_DELETE_HIMSELF:
		message = "�� �� ������ �������� ��i� ���i����� �����";
		break;
	case USER_DELETE_SUCCESS:
		message = "���������� ��� ��������� ���i���";
		break;	
	case USER_DELETE_FAIL:
		message = "������� ��� ��������i �����������";
		break;
	case NOT_ALLOWED:
		message = "� ��� ���� ���� �� ��������� �i�� �������";
		break;
	case GROUP_NOT_FOUND:
		message = "���� ����� �� i���";
		break;
	case GROUP_CANT_CREATE:
		message = "�� ���� �������� ����� � ����� i�����";
		break;
	case GROUP_CREATED_SUCCESS:
		message = "����� �������� ���i���";
		break;
	case GROUP_NOT_CHOSEN:
		message = "����� �� ���� �������. ���� �����, �����i�� �����";
		break;
	case STUDENTS_FILE_NOT_FOUND:
		message = "�� ���� ����� ������ �������i�";
		break;
	case BAD_YEAR:
		message = "�� ����� ���i���� �i�";
		break;
	case BAD_MONTH:
		message = "�� ����� ���i���� �i����";
		break;
	case STUDENT_NOT_FOUND:
		message = "������� �� ���������";
		break;
	case BAD_DATE:
		message = "�� ����� ���i��� ����";
		break;
	case BAD_MARK:
		message = "�� ����� ���i��� ��i���";
		break;
	case ENTER_NAME:
		message = "����i�� i�'� �����������: ";
		break;
	case ENTER_PASSWORD:
		message = "����i�� ������: ";
		break;
	case ENTER_PASSWORD_AGAIN:
		message = "����i�� ������ �� ���: ";
		break;
	case ENTER_GROUP_NAME:
		message = "����i�� ����� �����:";
		break;
	case ENTER_STUDENT_NAME:
		message = "����i�� i�'� ��������: ";
		break;
	case STUDENTS_EMPTY:
		message = "�������i� �� ��������";
		break;
	case JOURNAL_NAMES:
		message = "��������";
		break;
	case ENTER_YEAR:
		message = "����i�� �i�: ";
		break;
	case ENTER_MONTH:
		message = "����i�� �i����:  ";
		break;
	case WRITE_DOWN:
		message = "��� ������ ����� �����, ����i�� ���i ���i: ";
		break;
	case ENTER_DATE:
		message = "����i�� ���� � ������ ������i �i�.�i����.����: ";
		break;
	case ENTER_MARK:
		message = "����i�� ��i���(1-5), ��� 0, ���� ������� �� ��� �������i�: ";
		break;
	}

	return message;
}