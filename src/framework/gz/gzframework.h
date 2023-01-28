/**
 * @file
 *
 * @brief Implementation of interface for service management and event processing.
 *
 * @copyright Las Marionetas is free software: you can redistribute it and/or
 *            modify it under the terms of the GNU General Public License
 *            as published by the Free Software Foundation, either version
 *            2 of the License, or (at your option) any later version.
 *            A full copy of the GNU General Public License can be found in
 *            LICENSE
 */

#pragma once
#include "igzframework.h"
#include "igzframeworkhooks.h"

class cGZFrameWork : public cIGZFrameWork, public cIGZFrameWorkHooks
{
public:

    /**
     * @brief Adds a service to the service registry.
     *
     * This will allow the service to be accessed from other COM directors, allowing code to be shared between modules.
     * If the service needs to process on active or idle ticks, it should be registered for them specifically.
     *
     * @see AddToTick(cIGZSystemService* service)
     * @see AddToOnIdle(cIGZSystemService* service)
     */
    bool AddSystemService(cIGZSystemService *service) override;

    /**
     * @brief Removes a system service from the service registry.
     */
    virtual bool RemoveSystemService(cIGZSystemService *service) override;

    /**
     * @brief Gets a pointer to a system service using a given interface.
     * @param srvid The service ID to get the pointer for.
     * @param riid The interface ID to the interface the service will be used as.
     * @param service A pointer to the pointer to store the service in.
     * @return Whether the service was successfully retrieved.
     * @see cIGZUnknown::QueryInterface(uint32_t riid, void** obj)
     */
    virtual bool GetSystemService(uint32_t srvid, uint32_t riid, void **service) override;

    /**
     * @brief Uses a cIGZUnknownEnumerator to iterate over system services.
     *
     * @warning Structure of cIGZUnknownEnumerator currently unknown so unuseable.
     */
    virtual bool EnumSystemServices(cIGUnknownEnumerator &enumerator, cIGZUnknown *service, uint32_t unk) override;

    /**
     * @brief Subscribes an object to framework event callbacks.
     */
    virtual bool AddHook(cIGZFrameWorkHooks *hooks) override;

    /**
     * @brief Unsubscribes an object from framework event callbacks.
     */
    virtual bool RemoveHook(cIGZFrameWorkHooks *hooks) override;

    virtual bool HookPreFrameWorkInit() override;
    virtual bool HookPreAppInit() override;
    virtual bool HookPostAppInit() override;
    virtual bool HookPreAppShutdown() override;
    virtual bool HookPostAppShutdown() override;
    virtual bool HookPostSystemServiceShutdown() override;
    virtual bool HookAbortiveQuit() override;
    virtual bool HookOnInstall() override;

    /**
     * @brief Activates the on-tick event for a system service.
     *
     * @warning Running every tick has performance implications, acting on messages may be a better model.
     */
    virtual bool AddToTick(cIGZSystemService *service) override;

    /**
     * @brief Deactivates the on-tick event for a system service.
     */
    virtual bool RemoveFromTick(cIGZSystemService *service) override;

    /**
     * @brief Activates the on-idle event for a system service.
     * @see AddToTick(cIGZSystemService* service)
     */
    virtual bool AddToOnIdle(cIGZSystemService *service) override;

    /**
     * @brief Deactivates the on-idle event for a system service.
     */
    virtual bool RemoveFromOnIdle(cIGZSystemService *service) override;

    /**
     * @brief Get the interval at which the idle tick occurs, in milliseconds.
     */
    virtual int32_t GetOnIdleInterval() override;

    /**
     * @brief Sets the idle tick interval in miliseconds.
     */
    virtual bool SetOnIdleInterval(int32_t nInterval) override;

    /**
     * @brief Called when the game has an active tick.
     * @param time_elapsed Time since the last tick, in milliseconds.
     */
    virtual bool OnTick(uint32_t time_elapsed) override;

    /**
     * @brief Called when the game has an idle tick.
     */
    virtual bool OnIdle() override;

    /**
     * @brief Whether or not tick events are enabled.
     */
    virtual bool IsTickEnabled() override;

    /**
     * @brief Sets whether tick events are enabled.
     * @param tick Whether to enable tick events or not.
     * @return Pointer to the current object.
     */
    virtual cGZFrameWork *ToggleTick(bool tick) override;

    /**
     * @brief Prepares the game for shutdown for the given reason
     * @return quit_reason
     */
    virtual int32_t Quit(int32_t quit_reason) override;

    /**
     * @brief Immediately terminates the game for the given reason.
     */
    virtual void AbortiveQuit(int32_t quit_reason) override;

    /**
     * @return The command line passed to the application.
     */
    virtual char *CommandLine() override;

    /**
     * @return Whether the game is in an installation-only mode.
     */
    virtual bool IsInstall() override;

    /**
     * @return A pointer to the parent COM.
     */
    virtual cIGZCOM *GetCOMObject() override;

    virtual FrameworkState GetState() override;

    virtual void *GetDebugStream() override;
    virtual int32_t DefaultDebugStream() override;
    virtual void *DebugStream() override;
    virtual bool SetDebugStream(void *debug_stream) override;
    virtual bool SetDebugLevel(int32_t level) override;
    virtual int32_t GetDebugLevel() override;

    virtual int32_t StdOut() override;
    virtual int32_t StdErr() override;
    virtual int32_t StdIn() override;

    virtual void *GetStream() override;
    virtual bool SetStream(int32_t unk, cIGZUnknown *stream) override;

    /**
     * @brief Sets an application to associate with the framework.
     */
    virtual bool SetApplication(cIGZApp *app) override;

    /**
     * @brief Sets the framework.
     */
    void sSetFramework(cGZFrameWork* frameWork);

    /**
     * @return The application associated with this framework.
     */
    virtual cIGZApp *const Application() override;

    /**
     * @brief Reports a fatal error using the text provided.
     */
    virtual void ReportException(char const *except_text) override;

    /**
     * @brief Obtains an exception notification object.
     */
    virtual cIGZExceptionNotification *ExceptionNotificationObj() override;

    static cGZFrameWork *mpFrameWork;
    static int* mpSavedFrameWork;
};

#ifndef DLL_EXPORT
cGZFrameWork* RZGetFrameWork();
#endif