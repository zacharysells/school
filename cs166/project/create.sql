-- Zachary Sells, SID: 861013217
-- Jaijeet Kakkar, SID: 860974524
-- Group #3

CREATE TABLE IF NOT EXISTS users
(
  userid varchar(10) NOT NULL UNIQUE,
  password varchar(10) NOT NULL,
  email varchar(50) NOT NULL,
  name varchar(50),
  dateofbirth date,
  PRIMARY KEY (userid)
);

CREATE TABLE IF NOT EXISTS work_experience
(
  userid varchar(10) NOT NULL,
  company varchar(50) NOT NULL,
  role varchar(50) NOT NULL,
  location varchar(50),
  startdate date NOT NULL,
  enddate date,
  PRIMARY KEY (userid, company, startdate),
  FOREIGN KEY (userid) REFERENCES users(userid)
);

CREATE TABLE IF NOT EXISTS educational_details
(
  userid varchar(10) NOT NULL UNIQUE,
  institution_name varchar(50) NOT NULL,
  major varchar(50) NOT NULL UNIQUE,
  degree varchar(50) NOT NULL UNIQUE,
  startdate date,
  enddate date,
  FOREIGN KEY (userid) REFERENCES users(userid)
);

CREATE TABLE IF NOT EXISTS message
(
  messageid SERIAL NOT NULL UNIQUE, -- SERIAL data type is equivalent to AUTO_INCREMENT
  senderid varchar(10) NOT NULL,
  receiverid varchar(10) NOT NULL,
  contents text NOT NULL,
  sendtime timestamp NOT NULL,
  deletestatus int,
  status varchar(30) NOT NULL,
  PRIMARY KEY (messageid),
  FOREIGN KEY (senderid) REFERENCES users(userid),
  FOREIGN KEY (receiverid) REFERENCES users(userid)
);

CREATE TABLE IF NOT EXISTS connection
(
  userid varchar(10) NOT NULL,
  connectionid varchar(10) NOT NULL,
  status varchar(30) NOT NULL,
  PRIMARY KEY (userid, connectionid),
  FOREIGN KEY (userid) REFERENCES users(userid),
  FOREIGN KEY (connectionid) REFERENCES users(userid)
);
