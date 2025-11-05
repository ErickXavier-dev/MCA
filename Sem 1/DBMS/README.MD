[Online PLSQL Compiler](https://onecompiler.com/plsql)
```
create table Waterbill(cno number(5) primary key, name varchar(25), prev_read number(15), cur_read number(15), amount number(10,5));

insert into Waterbill values (101, 'Gowri Parvathy', 135, 120, 0);
insert into Waterbill values (102, 'Elvin', 1102, 1070, 0);
insert into Waterbill values (103, 'Niranjana', 9000, 7000, 0);
insert into Waterbill values (104, 'Narayanan', 10000, 8500, 0);
insert into Waterbill values (105, 'Kiran', 16000, 15500, 0);
insert into Waterbill values (106, 'Amal', 22000, 21500, 0);

update Waterbill set prev_read = 10000, cur_read = 12000 where cno = 101;
update Waterbill set prev_read = 12000, cur_read = 18000 where cno = 102;
update Waterbill set prev_read = 14500, cur_read = 25500 where cno = 103;
update Waterbill set prev_read = 15000, cur_read = 32000 where cno = 104;
update Waterbill set prev_read = 12000, cur_read = 22000 where cno = 105;
update Waterbill set prev_read = 12000, cur_read = 12000 where cno = 106;

set serveroutput on

select * from Waterbill;

declare
  cursor c1 is select cno, cur_read, prev_read, amount from Waterbill;
  vcno Waterbill.cno%type;
  vprev Waterbill.prev_read%type;
  vcur Waterbill.cur_read%type;
  usage Waterbill.cur_read%type;
vamt number(15,2);
begin
  open c1;
  loop
    fetch c1 into vcno, vcur, vprev, vamt;
    exit when c1%NOTFOUND;
    usage := vcur-vprev;
    if usage<=5000 then
      vamt := 72+(0.0145*usage);
    elsif usage>5000 and usage<=10000 then
      vamt := 72+(14.50*5)+(0.0145*(usage-5000));
    elsif usage>10000 and usage<=15000 then
      vamt := 144+(14.50*10)+(0.0155*(usage-5000));
    elsif usage>15000 and usage<=20000 then
      vamt := 17.50;
    else
      vamt := 72;
    end if;
    update Waterbill set amount = vamt where cno = vcno;
  end loop;
close c1;
end;
/
select * from Waterbill;
```
The above is a sample code to be executed in online compiler.