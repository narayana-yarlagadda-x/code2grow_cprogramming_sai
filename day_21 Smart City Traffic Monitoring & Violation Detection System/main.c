#include <stdio.h>
#include <stdlib.h>

void inputData(int vehicleID[], int speed[], int lane[], int *n)
{
int i;
printf("Enter number of vehicles (max 30): ");
scanf("%d", n);

if (*n > 30) {
printf("Limit exceeded! Setting n = 30\n");
*n = 30;
}

for (i = 0; i < *n; i++) {
printf("\nVehicle %d Details:\n", i + 1);

printf("Enter Vehicle ID (4-digit): ");
scanf("%d", &vehicleID[i]);

do
{
printf("Enter Speed (positive): ");
scanf("%d", &speed[i]);
}
while (speed[i] <= 0);

do
{
printf("Enter Lane (1-4): ");
scanf("%d", &lane[i]);
} while (lane[i] < 1 || lane[i] > 4);
}
}

int countSpeedViolations(int speed[], int n, int *highest, int *lowest) {
int count = 0;
*highest = speed[0];
*lowest = speed[0];

for (int i = 0; i < n; i++) {
if (speed[i] > 80)
count++;

if (speed[i] > *highest)
*highest = speed[i];

if (speed[i] < *lowest)
*lowest = speed[i];
}
return count;
}

int countLaneViolations(int vehicleID[], int lane[], int n, int *maxSeverityIndex) {
int count = 0, severity, maxSeverity = -1;

for (int i = 0; i < n; i++) {
severity = abs((vehicleID[i] % 4) - lane[i]);

if ((vehicleID[i] % 4) != lane[i])
count++;

if (severity > maxSeverity) {
maxSeverity = severity;
*maxSeverityIndex = i;
}
}
return count;
}

int busiestLane(int laneCount[]) {
int max = 0;
for (int i = 1; i < 4; i++)
if (laneCount[i] > laneCount[max])
max = i;
return max + 1;
}

int leastBusyLane(int laneCount[]) {
int min = 0;
for (int i = 1; i < 4; i++)
if (laneCount[i] < laneCount[min])
min = i;
return min + 1;
}

void displayReport(int vehicleID[], int speed[], int lane[], int n) {
printf("\n=====================================================\n");
printf("   VEHICLE TRAFFIC REPORT\n");
printf("=====================================================\n");
printf("VehID   Speed   Lane   SpeedViolation   LaneViolation\n");

for (int i = 0; i < n; i++) {
int sp = (speed[i] > 80);
int ln = ((vehicleID[i] % 4) != lane[i]);

printf("%4d   %5d    %2d        %4d              %4d\n",
vehicleID[i], speed[i], lane[i], sp, ln);
}
}

int main() {
int vehicleID[30], speed[30], lane[30];
int n;

inputData(vehicleID, speed, lane, &n);


int highest, lowest;
int speedViolations = countSpeedViolations(speed, n, &highest, &lowest);


int maxSeverityIndex;
int laneViolations = countLaneViolations(vehicleID, lane, n, &maxSeverityIndex);


int laneCount[4] = {0};
for (int i = 0; i < n; i++)
laneCount[lane[i] - 1]++;

int busy = busiestLane(laneCount);
int low = leastBusyLane(laneCount);


displayReport(vehicleID, speed, lane, n);

printf("\n========== SUMMARY ==========\n");
printf("Total Speed Violations: %d\n", speedViolations);
printf("Highest Speed: %d\n", highest);
printf("Lowest Speed: %d\n", lowest);
printf("Total Lane Violations: %d\n", laneViolations);
printf("Most Severe Violation Vehicle: ID %d\n", vehicleID[maxSeverityIndex]);
printf("Busiest Lane: %d\n", busy);
printf("Least Busy Lane: %d\n", low);
printf("Total Traffic Volume: %d\n", n);

return 0;
}
