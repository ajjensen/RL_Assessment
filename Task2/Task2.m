%% ROCKET LAB ASSESSMENT: TASK 2
clear;
clc;

%% Load the data from the provided graph
indata = "3U_2Springs.csv";
col1 = 'Mass';
col2 = 'Velocity';
colHeaders = {col1 col2};
ejVel = readtable(indata);
ejVel.Properties.VariableNames = colHeaders;

%% Calculate spring constant (k) and damping coeffiecient (b)

% Unfortunately, I could not figure this one out...
