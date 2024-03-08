class ACE_Medical_Treatment_Actions {
    class CheckPulse;
    class ListenToLungs: CheckPulse {
        displayName = CSTRING(auscultateLung_display);
        displayNameProgress = CSTRING(listening_progress);
        treatmentTime = QGVAR(stethoscopeListeningTime);
        allowedSelections[] = {"Body"};
        allowSelfTreatment = 0;
        category = "airway";
        medicRequired = 0;
        consumeItem = 0;
        callbackStart = QUOTE(_medic setVariable [ARR_3(QQGVAR(usingStethoscope),true,true)]; [ARR_2(_medic,_patient)] call FUNC(listenLungs));
        callbackSuccess = QUOTE(_medic setVariable [ARR_3(QQGVAR(usingStethoscope),false,true)]);
        callbackProgress = "";
        callbackFailure = QUOTE(_medic setVariable [ARR_3(QQGVAR(usingStethoscope),false,true)]);
        condition = "true";
        items[] = {"kat_stethoscope"};
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
    };
    class CheckBreathing: CheckPulse {
        displayName = CSTRING(Check_Breathing);
        displayNameProgress = CSTRING(Check_Breathing_Progress);
        category = "airway";
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        medicRequired = 0;
        treatmentTime = 2;
        condition = "true";
        callbackSuccess = QFUNC(checkBreathing);
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "";
        animationMedicProne = "";
        sounds[] = {};
    };
    class InspectChest: CheckPulse {
        displayName = CSTRING(inspectChest_display);
        displayNameProgress = CSTRING(inspectChest_progress);
        category = "airway";
        treatmentTime = QGVAR(InspectChest_time);
        allowedSelections[] = {"Body"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(inspectChest_medLvl);
        condition = QUOTE(!([_patient] call ACEFUNC(common,isAwake)) && (missionNamespace getVariable [ARR_2(QQGVAR(enable),true)]) && (missionNamespace getVariable [ARR_2(QQGVAR(inspectChest_enable),0)] > 0));
        callbackSuccess = QUOTE([ARR_3(_medic,_patient,true)] call EFUNC(airway,handleRecoveryPosition); [ARR_2(_medic,_patient)] call FUNC(inspectChest););
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
        animationMedic = "AinvPknlMstpSnonWnonDr_medic4";
    };
    class Pulseoximeter {
        displayName = CSTRING(Pulseoximeter_Display);
        displayNameProgress = CSTRING(placing);
        category = "examine";
        treatmentLocations = 0;
        allowedSelections[] = {"LeftArm", "RightArm"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Pulseoximeter);
        treatmentTime = 2;
        items[] = {"kat_Pulseoximeter"};
        condition = QUOTE(!(_patient getVariable [ARR_2(QQGVAR(pulseoximeter),false)]) && !([ARR_2(_patient,_bodyPart)] call FUNC(checkPulseOximeter)));
        callbackSuccess = QFUNC(treatmentAdvanced_pulseoximeter);
        callbackFailure = "";
        callbackProgress = "";
        consumeItem = 1;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
    };
    class RemovePulseoximeter {
        displayName = CSTRING(Pulseoximeter_Display_Remove);
        displayNameProgress = CSTRING(remove);
        category = "examine";
        treatmentLocations = 0;
        allowedSelections[] = {"LeftArm", "RightArm"};
        allowSelfTreatment = 1;
        medicRequired = QGVAR(medLvl_Pulseoximeter);
        treatmentTime = 2;
        items[] = {};
        condition = QUOTE([ARR_2(_patient,_bodyPart)] call FUNC(checkPulseOximeter));
        callbackSuccess = QFUNC(treatmentAdvanced_removePulseoximeter);
        callbackFailure = "";
        callbackProgress = "";
        consumeItem = 0;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
    };
    class ChestSeal {
        displayName = CSTRING(chestseal_display);
        displayNameProgress = CSTRING(treating);
        category = "airway";
        treatmentLocations = 0;
        allowedSelections[] = {"Body"};
        allowSelfTreatment = QGVAR(enable_selfChestseal);
        medicRequired = QGVAR(medLvl_Chestseal);
        treatmentTime = 7;
        items[] = {"kat_chestSeal"};
        condition = "true";
        callbackSuccess = QUOTE([ARR_2(_medic,_patient)] call EFUNC(airway,handleRecoveryPosition); [ARR_6(_medic,_patient,_bodyPart,_className,objNull,_usedItem)] call FUNC(treatmentAdvanced_chestSeal););
        callbackFailure = "";
        callbackProgress = "";
        consumeItem = 1;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
    };
    class HemopneumothoraxTreatment {
        displayName = CSTRING(hemopneumothorax_display);
        displayNameProgress = CSTRING(treating);
        category = "airway";
        treatmentLocations = 0;
        allowedSelections[] = {"Body"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_hemopneumothoraxTreatment);
        treatmentTime = 7;
        items[] = {"kat_aatKit"};
        condition = "true";
        callbackSuccess = QUOTE([ARR_2(_medic,_patient)] call EFUNC(airway,handleRecoveryPosition); [ARR_6(_medic,_patient,_bodyPart,_className,objNull,_usedItem)] call FUNC(treatmentAdvanced_hemopneumothorax););
        callbackFailure = "";
        callbackProgress = "";
        consumeItem = 1;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
    };
    class TensionpneumothoraxTreatment {
        displayName = CSTRING(tensionpneumothorax_display);
        displayNameProgress = CSTRING(treating);
        category = "airway";
        treatmentLocations = 0;
        allowedSelections[] = {"Body"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_hemopneumothoraxTreatment);
        treatmentTime = 7;
        items[] = {"kat_aatKit"};
        condition = "true";
        callbackSuccess = QUOTE([ARR_2(_medic,_patient)] call EFUNC(airway,handleRecoveryPosition); [ARR_6(_medic,_patient,_bodyPart,_className,objNull,_usedItem)] call FUNC(treatmentAdvanced_tensionpneumothorax););
        callbackFailure = "";
        callbackProgress = "";
        consumeItem = 1;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
    };
    class ncdKit: TensionpneumothoraxTreatment {
        displayName = CSTRING(tensionpneumothoraxNCDKit_display);
        displayNameProgress = CSTRING(treating);
        category = "airway";
        treatmentLocations = 0;
        allowedSelections[] = {"Body"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_hemopneumothoraxTreatment);
        treatmentTime = 7;
        items[] = {"kat_ncdKit"};
        condition = "true";
        callbackSuccess = QUOTE([ARR_2(_medic,_patient)] call EFUNC(airway,handleRecoveryPosition); [ARR_6(_medic,_patient,_bodyPart,_className,objNull,_usedItem)] call FUNC(treatmentAdvanced_tensionpneumothorax););
        callbackFailure = "";
        callbackProgress = "";
        consumeItem = 1;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
    };
    class DisablePulseOximeterAudio {
        displayName = CSTRING(PulseOximeter_Action_removeSound);
        displayNameProgress = "";
        icon = "";
        category = "examine";
        treatmentLocations = 0;
        medicRequired = 0;
        allowSelfTreatment = 1;
        allowedSelections[] = {"LeftArm", "RightArm"};
        treatmentTime = 0.01;
        condition = QUOTE([ARR_2(_patient,_bodyPart)] call FUNC(checkPulseOximeter) && _patient getVariable [ARR_2(QQGVAR(PulseOximeter_VolumePatient),false)]);
        callbackProgress = "";
        callbackStart = "";
        callbackFailure = "";
        callbackSuccess = QUOTE(_patient setVariable [ARR_3(QQGVAR(PulseOximeter_VolumePatient),false,true)]);
        animationPatient = "";
        animationMedic = "";
        litter[] = {};
    };
    class EnablePulseOximeterAudio: DisablePulseOximeterAudio {
        displayName = CSTRING(PulseOximeter_Action_addSound);
        condition = QUOTE([ARR_2(_patient,_bodyPart)] call FUNC(checkPulseOximeter) && !(_patient getVariable [ARR_2(QQGVAR(PulseOximeter_VolumePatient),false)]));
        callbackSuccess = QUOTE(_patient setVariable [ARR_3(QQGVAR(PulseOximeter_VolumePatient),true,true)]);
    };
    class UseBVM {
        displayName = CSTRING(UseBVM);
        displayNameProgress = "";
        category = "airway";
        treatmentLocations = 0;
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_BVM);
        treatmentTime = 0.01;
        consumeItem = 0;
        items[] = {"kat_BVM"};
        condition = QUOTE(_patient call FUNC(canUseBVM));
        callbackStart = "";
        callbackSuccess = QUOTE([ARR_3(_medic,_patient,true)] call EFUNC(airway,handleRecoveryPosition); [ARR_2(_medic,_patient)] call FUNC(useBVM););
        callbackFailure = "";
        callbackProgress = "";
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon"};
        animationMedic = "";
        animationMedicProne = "";
        litter[] = {};
        icon = QPATHTOF(ui\BVM_ui.paa);
    };
    class UsePocketBVM: UseBVM {
        displayName = CSTRING(UsePocketBVM);
        medicRequired = QGVAR(medLvl_PocketBVM);
        items[] = {"kat_pocketBVM"};
        condition = QUOTE(_patient call FUNC(canUseBVM));
        callbackSuccess = QUOTE([ARR_3(_medic,_patient,true)] call EFUNC(airway,handleRecoveryPosition); [ARR_4(_medic,_patient,true,false)] call FUNC(useBVM););
    };
    class UseBVMPortableOxygen: UseBVM {
        displayName = CSTRING(UseBVM_PortableOxygen);
        medicRequired = QGVAR(medLvl_BVM_Oxygen);
        items[] = {"kat_BVM"};
        condition = QUOTE(_patient call FUNC(canUseBVM) && _medic call FUNC(hasOxygenTank) && (GVAR(locationProvideOxygen) isEqualTo 0 || !((GVAR(locationProvideOxygen) in [ARR_2(2,3)] && _patient call ACEFUNC(medical_treatment,isInMedicalFacility)) || ((GVAR(locationProvideOxygen) in [ARR_2(1,3)] && _patient call ACEFUNC(medical_treatment,isInMedicalVehicle))))));
        callbackSuccess = QUOTE([ARR_3(_medic,_patient,true)] call EFUNC(airway,handleRecoveryPosition); [ARR_5(_medic,_patient,false,true,1)] call FUNC(useBVM););
    };
    class UseBVMPortableOxygenVehicle: UseBVM {
        displayName = CSTRING(UseBVM_PortableOxygen_Vehicle);
        medicRequired = QGVAR(medLvl_BVM_Oxygen);
        items[] = {"kat_BVM"};
        condition = QUOTE(_patient call FUNC(canUseBVM) && [ARR_2((vehicle _medic),true)] call FUNC(hasOxygenTank) && ((vehicle _medic) != _medic) && (vehicle _medic) isEqualTo (vehicle _patient));
        callbackSuccess = QUOTE([ARR_3(_medic,_patient,true)] call EFUNC(airway,handleRecoveryPosition); [ARR_5(_medic,_patient,false,true,2)] call FUNC(useBVM););
    };
    class UseBVMOxygen: UseBVM {
        displayName = CSTRING(UseBVM_Oxygen);
        medicRequired = QGVAR(medLvl_BVM_Oxygen);
        items[] = {"kat_BVM"};
        condition = QUOTE(_patient call FUNC(canUseBVM) && ((GVAR(locationProvideOxygen) in [ARR_2(2,3)] && _patient call ACEFUNC(medical_treatment,isInMedicalFacility)) || (GVAR(locationProvideOxygen) in [ARR_2(1,3)] && _patient call ACEFUNC(medical_treatment,isInMedicalVehicle))));
        callbackSuccess = QUOTE([ARR_3(_medic,_patient,true)] call EFUNC(airway,handleRecoveryPosition); [ARR_4(_medic,_patient,false,true)] call FUNC(useBVM););
    };
    class NasalCannula {
        displayName = CSTRING(NasalCannula_Display);
        displayNameProgress = ECSTRING(airway,action_placing);
        category = "airway";
        treatmentLocations = 0;
        allowedSelections[] = {"Head"};
        allowSelfTreatment = 0;
        medicRequired = QGVAR(medLvl_NasalCannula);
        treatmentTime = QGVAR(NasalCannula_time);
        items[] = {"kat_nasal"};
        condition = QUOTE((missionNamespace getVariable [ARR_2(QQGVAR(enable),true)]) && !(_patient getVariable [ARR_2(QQGVAR(etco2Monitor), [])] findIf {_x == "NasalCannula"} > -1));
        callbackSuccess = QUOTE([ARR_6(_medic,_patient,_bodyPart,_className,objNull,_usedItem)] call FUNC(treatmentAdvanced_nasalCannula));
        callbackFailure = "";
        callbackProgress = "";
        callbackCondition = "useCondition";
        consumeItem = 1;
        animationPatient = "";
        animationPatientUnconscious = "AinjPpneMstpSnonWrflDnon_rolltoback";
        animationPatientUnconsciousExcludeOn[] = {"ainjppnemstpsnonwrfldnon", "kat_recoveryposition"};
        animationMedic = "AinvPknlMstpSlayWrflDnon_medicOther";
        animationMedicProne = "AinvPpneMstpSlayW[wpn]Dnon_medicOther";
        animationMedicSelf = "AinvPknlMstpSlayW[wpn]Dnon_medic";
        animationMedicSelfProne = "AinvPpneMstpSlayW[wpn]Dnon_medic";
        litter[] = {};
        icon = QPATHTOEF(airway,ui\larynx.paa); // TODO update to nasal specific icon
    };
    class RemoveNasalCannula : NasalCannula {
        displayName = CSTRING(Cancel_NasalCannula);
        displayNameProgress = ECSTRING(airway,action_removing);
        medicRequired = QGVAR(medLvl_NasalCannula);
        treatmentTime = QGVAR(NasalCannula_time);
        items[] = {};
        condition = QUOTE((missionNamespace getVariable [ARR_2(QQGVAR(enable),true)]) && !(_patient getVariable [ARR_2(QQGVAR(etco2Monitor), [])] findIf {_x == "NasalCannula"} > -1));
        callbackSuccess = QUOTE(_patient setVariable [ARR_3(QQGVAR(etco2Monitor),false,true)]); //todo make this work
    };
};
