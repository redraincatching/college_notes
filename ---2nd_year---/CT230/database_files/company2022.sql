-- phpMyAdmin SQL Dump
-- version 4.6.6
-- https://www.phpmyadmin.net/
--
-- PHP Version: 5.6.26-pl0-gentoo

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";



-- --------------------------------------------------------

--
-- Table structure and Primary Key Index for table `department`
--

CREATE TABLE `department` (
  `dnumber` int(20) NOT NULL PRIMARY KEY,
  `dname` varchar(50) DEFAULT NULL,
  `mgrssn` bigint(20) DEFAULT NULL,
  `mgrstartdate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`dnumber`, `dname`, `mgrssn`, `mgrstartdate`) VALUES
(1, 'Headquarters', 888665555, '2019-06-19'),
(4, 'Administration', 987654321, '2015-01-01'),
(5, 'Research', 333445555, '2018-05-22');

-- --------------------------------------------------------

--
-- Table structure and Primary Key Index for table `dependent`
--

CREATE TABLE `dependent` (
  `essn` bigint(20) NOT NULL,
  `dependent_name` varchar(50) NOT NULL,
  `gender` varchar(50) DEFAULT NULL,
  `bdate` date DEFAULT NULL,
  `relationship` varchar(50) DEFAULT NULL,
   PRIMARY KEY (`essn`,`dependent_name`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `dependent`
--

INSERT INTO `dependent` (`essn`, `dependent_name`, `gender`, `bdate`, `relationship`) VALUES
(123456789, 'Alice', 'Woman', '2008-12-30', 'Daughter'),
(123456789, 'Elizabeth', 'Woman', '1976-05-05', 'Spouse'),
(123456789, 'Michael', 'Man', '2011-01-04', 'Son'),
(333445555, 'Alice', 'Woman', '2010-04-05', 'Daughter'),
(333445555, 'Joy', 'Woman', '1981-05-03', 'Spouse'),
(333445555, 'Theodore', 'Man', '2014-10-25', 'Son'),
(987654321, 'Abner', 'Woman', '1992-02-28', 'Spouse');

-- --------------------------------------------------------

--
-- Table structure and Primary Key Index for table `dept_locations`
--

CREATE TABLE `dept_locations` (
  `dnumber` int(11) NOT NULL,
  `dlocation` varchar(20) NOT NULL,
   PRIMARY KEY (`dnumber`,`dlocation`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `dept_locations`
--

INSERT INTO `dept_locations` (`dnumber`, `dlocation`) VALUES
(1, 'Houston'),
(4, 'Stafford'),
(5, 'Bellaire'),
(5, 'Houston'),
(5, 'Sugarland');

-- --------------------------------------------------------

--
-- Table structure and Primary Key Index for table `employee`
--

CREATE TABLE `employee` (
  `fname` varchar(50) DEFAULT NULL,
  `minit` varchar(1) DEFAULT NULL,
  `lname` varchar(50) DEFAULT NULL,
  `ssn` bigint(20) NOT NULL PRIMARY KEY,
  `bdate` date DEFAULT NULL,
  `address` varchar(100) DEFAULT NULL,
  `gender` varchar(50) DEFAULT NULL,
  `salary` double DEFAULT NULL,
  `superssn` bigint(20) DEFAULT NULL,
  `dno` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `employee`
--

INSERT INTO `employee` (`fname`, `minit`, `lname`, `ssn`, `bdate`, `address`, `gender`, `salary`, `superssn`, `dno`) VALUES
('John', 'B', 'Smith', 123456789, '1975-01-09', '731 Fondren, Houston, Tx', 'Man', 55250, 333445555, 5),
('Franklin', 'T', 'Wong', 333445555, '1980-12-08', '638 Voss, Houston, TX', 'Man', 65000, 888665555, 5),
('Joyce', 'A', 'English', 453453453, '1972-07-31', '5631 Rice, Houston, TX', 'Woman', 44183, 333445555, 5),
('Ramesh', 'K', 'Narayan', 666884444, '1995-09-15', '975 Fire Oak, Humble, TX', 'Man', 60000, 333445555, 5),
('James', 'E', 'Borg', 888665555, '1997-11-10', '450 Stone, Houston, TX', 'Man', 94199, NULL, 1),
('Jennifer', 'S', 'Wallace', 987654321, '1991-06-20', '291 Berry, Bellaire, TX', 'Woman', 69240, 888665555, 4),
('Ahmad', 'V', 'Jabbar', 987987987, '2000-03-29', '980 Dallas, Houston, TX', 'Man', 44183, 987654321, 4),
('Alicia', 'J', 'Zelaya', 999887777, '1998-07-19', '3321 Castle, Spring, TX', 'Non-binary', 44183, 987654321, 4);

-- --------------------------------------------------------

--
-- Table structure and Primary Key Index for table `project`
--

CREATE TABLE `project` (
  `pname` varchar(20) DEFAULT NULL,
  `pnumber` int(11) NOT NULL PRIMARY KEY,
  `plocation` varchar(20) DEFAULT NULL,
  `dnum` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `project`
--

INSERT INTO `project` (`pname`, `pnumber`, `plocation`, `dnum`) VALUES
('ProductX', 1, 'Bellaire', 5),
('ProductY', 2, 'Sugarland', 5),
('ProductZ', 3, 'Houston', 5),
('Computerization', 10, 'Stafford', 4),
('Reorganization', 20, 'Houston', 1),
('Newbenefits', 30, 'Stafford', 4);

-- --------------------------------------------------------

--
-- Table structure and Primary Key Index for table `works_on`
--

CREATE TABLE `works_on` (
  `essn` bigint(20) NOT NULL,
  `pno` int(11) NOT NULL,
  `hours` double DEFAULT NULL,
  PRIMARY KEY (`essn`,`pno`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `works_on`
--

INSERT INTO `works_on` (`essn`, `pno`, `hours`) VALUES
(123456789, 1, 32.5),
(123456789, 2, 7.5),
(333445555, 2, 10),
(333445555, 3, 10),
(333445555, 10, 10),
(333445555, 20, 10),
(453453453, 1, 20),
(453453453, 2, 20),
(666884444, 3, 40),
(888665555, 20, 0),
(987654321, 20, 15),
(987654321, 30, 20),
(987987987, 10, 35),
(987987987, 30, 5),
(999887777, 30, 30);


--
-- Indexes and Constraints for dumped tables
--

--
-- Foreign Key indexes and constraints for table `department`
--
ALTER TABLE `department`
  ADD KEY `mgrssn` (`mgrssn`),
  ADD CONSTRAINT `department_ibfk_2` FOREIGN KEY (`mgrssn`) REFERENCES `employee` (`ssn`);

--
-- Foreign Key indexes and constraints for table `dependent`
--
ALTER TABLE `dependent`
  ADD CONSTRAINT `dependent_ibfk_1` FOREIGN KEY (`essn`) REFERENCES `employee` (`ssn`);

--
-- Foreign Key indexes and constraints for table `dept_locations`
--
ALTER TABLE `dept_locations`
  ADD KEY `dnumber` (`dnumber`),
  ADD CONSTRAINT `FK_dept_locations_dnumber` FOREIGN KEY (`dnumber`) REFERENCES `department` (`dnumber`);

--
-- Foreign Key indexes and constraints for table `employee`
--
ALTER TABLE `employee`
  ADD KEY `FK_employee_superssn` (`superssn`),
  ADD KEY `FK_employee_department_dno` (`dno`),
  ADD CONSTRAINT `FK_employee_department_dno` FOREIGN KEY (`dno`) REFERENCES `department` (`dnumber`),
  ADD CONSTRAINT `FK_employee_superssn` FOREIGN KEY (`superssn`) REFERENCES `employee` (`ssn`);

--
-- Foreign Key indexes and constraints for table `project`
--
ALTER TABLE `project`
  ADD KEY `dnum` (`dnum`),
  ADD CONSTRAINT `project_ibfk_1` FOREIGN KEY (`dnum`) REFERENCES `department` (`dnumber`);

--
-- Foreign Key indexes and constraints for table `works_on`
--
ALTER TABLE `works_on`
  ADD KEY `pno` (`pno`),
  ADD CONSTRAINT `FK1_works_on_essn` FOREIGN KEY (`essn`) REFERENCES `employee` (`ssn`),
  ADD CONSTRAINT `works_on_ibfk_1` FOREIGN KEY (`pno`) REFERENCES `project` (`pnumber`);

