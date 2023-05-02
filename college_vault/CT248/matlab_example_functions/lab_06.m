clear;
writefile = "updated_flights.csv";

%1
% records should be equal to 336766
flights = readtable("Flights.csv");
main_entries = height(flights);
flights(:,:);

%2
% converting origin and dest to string
flights.origin = string(flights.origin);
flights.dest = string(flights.dest);
flights(:,:);

%3
% using summary to find the number of missing values for dep time
summary(flights(:,"dep_delay"));

%4
% using isnan as a filter, remove rows with missing values
dep = isnan(flights.dep_delay);
flights_ne = flights(~dep, :);
flights_ne(:,:)

%5
% compare difference in heights
diff = height(flights) - height(flights_ne);
display(diff);

%6
% remove any delay > 120 minutes
flights_fin = flights_ne(~(flights_ne.dep_delay > 120),:);
flights_fin(:,:)

%7
% generate table and graph, grouped by month
[groups, month] = findgroups(flights_fin.Month);
avg_delay_mnth = splitapply(@mean, flights_fin.dep_delay, groups);

res1 = table(month, avg_delay_mnth);
disp(res1);
subplot(5,1,1);
plot(res1.month, res1.avg_delay_mnth, 'o-');
xlim([1 12]);
title("average delay by month");

%8
% average delay by hour
[groups, hour] = findgroups(flights_fin.hour);
avg_delay_hr = splitapply(@mean, flights_fin.dep_delay, groups);

res2 = table(hour, avg_delay_hr);
disp(res2);
subplot(5,1,2);
plot(res2.hour, res2.avg_delay_hr, 'o-');
xlim([5 23]);
title("average delay by hour");

%9
% average delay by month and origin
[groups, month, origin] = findgroups(flights_fin.Month, flights_fin.origin);
avg_delay_mnth_org = splitapply(@mean, flights_fin.dep_delay, groups);

res3 = table(month, origin, avg_delay_mnth_org);
disp(res3);

% jfk graph
subplot(5,1,3);
plot(res3.month(res3.origin == "JFK"), res3.avg_delay_mnth_org(res3.origin == "JFK"), 'o-');
ylim([0, 15]);
title('JFK');

% ewr graph
subplot(5,1,4);
plot(res3.month(res3.origin == "EWR"), res3.avg_delay_mnth_org(res3.origin == "EWR"), 'o-');
ylim([0, 15]);
title('EWR');

% lga graph
subplot(5,1,5);
plot(res3.month(res3.origin == "LGA"), res3.avg_delay_mnth_org(res3.origin == "LGA"), 'o-');
ylim([0, 15]);
title('LGA');